#include "stm32f10x_conf.h"

#include "rfm69.h"

/** @mainpage
	This library implements packet data transmittion via RFM69CW radiomodules.

	In order to use this library you need to include the @ref rfm69.h file, 
	declare extern global variables and call @ref rfm69_init() function, tat's
	all.
 
	After init radiomodule will switch into receive mode and will wait the 
	packet by the radio channel. To transmit the packet you need to place your
	data into @ref packet_buffer and call rfm69_transmit_start() function, then 
	after transmitting data, radiomodule will be switched by interrupt into 
	receive mode again.

	If radiomodule received the package successfully, the value of @ref 
	rfm69_condition equals to @ref RFM69_NEW_PACK and received data are 
	alreary in the @ref packet_buffer array. Then, when you are ready to 
	receive new data, you need to start the receive mode again by calling 
	rfm69_receive_start() function. 

	Note that radiomodule settings are in the rfm69.h file, packet size is in
	@ref packet_size global variable and the packet data are in @ref 
	packet_buffer global array and radiomodule state is in @ref rfm69_condition 
	variable. 
	
 @file rfm69.c @brief
	This is the main and only .c file, which contains all of the functions of rfm69 library.
*/

/* 	Global variables, connect this variables to use this library	 */
uint8_t packet_buffer[RFM69_BUFFER_SIZE - 2];	///< packet buffer
uint8_t rfm69_condition;						///< state of the radiomodule
uint8_t packet_size;							///< packet size

/** 
	@function
	External interrupt handler. It is called after radiomodule has transmitted
	or received the packet.
*/
void EXTI2_IRQHandler(void)
{
	int tmp;

    switch(rfm69_condition)
    {
        case RFM69_SLEEP :
            rfm69_sleep();
            break;
        case RFM69_STBY :
            rfm69_stby();
            break;
        case RFM69_RX :
            if(rfm69_read(REGIRQFLAGS2) & (1<<PAYLOADREADY))
            {
                tmp = rfm69_receive_small_packet();
                rfm69_stby();

				if(tmp)	rfm69_condition = RFM69_NEW_PACK;
	        	else 	rfm69_receive_start();    
			}
            break;
        case RFM69_TX :
            if(rfm69_read(REGIRQFLAGS2) & (1<<PACKETSENT))
            {
                rfm69_receive_start();
            }
            break;
    }
    EXTI_ClearITPendingBit(CRCOK_PKSent_Line);
}

/** 
	@function
	External interrupt handler. It is called after radiomodule FIFO threshold 
	level has been exceeded. This interrupt is useful for transmitting and 
	receiving packets bigger than 64 bytes. And it is not used in this firmware.
*/
void EXTI1_IRQHandler(void)
{
    switch(rfm69_condition)
    {
        case RFM69_SLEEP :
            break;
        case RFM69_STBY :
            break;
        case RFM69_RX :
            break;
        case RFM69_TX :
            break;
    }
    EXTI_ClearITPendingBit(FifoLevel_Line);
}

/** 
	@function
	External interrupt handler. It is called after rerceived signal has 
	exceeded FIFO threshold. And it is not used at that moment.
*/
void EXTI0_IRQHandler(void)
{
    switch(rfm69_condition)
    {
        case RFM69_SLEEP :
            rfm69_sleep();
            break;
        case RFM69_STBY :
            rfm69_stby();
            break;
        case RFM69_RX :
            break;
        case RFM69_TX :
            break;
    }
    EXTI_ClearITPendingBit(SyncAddr_Line);
}


/** 
	@function
	Write radiomodule register via SPI.
	@param address - register address
	@param data	- register value 
*/
void rfm69_write(uint8_t address, uint8_t data)
{
	__disable_irq();
	while (SPI_I2S_GetFlagStatus(SPI1, SPI_I2S_FLAG_BSY) == SET);           

	GPIO_ResetBits(NSS_Port, NSS_Pin);

    SPI_I2S_SendData(SPI1, (address | 0x80));                               
    while ( (SPI_I2S_GetFlagStatus(SPI1, SPI_I2S_FLAG_TXE) == RESET) && \
            (SPI_I2S_GetFlagStatus(SPI1, SPI_I2S_FLAG_BSY) == SET) );

    SPI_I2S_SendData(SPI1, data);                                           	

    while ( (SPI_I2S_GetFlagStatus(SPI1, SPI_I2S_FLAG_RXNE) == RESET) && \
            (SPI_I2S_GetFlagStatus(SPI1, SPI_I2S_FLAG_BSY) == SET) );
    SPI_I2S_ReceiveData(SPI1);												

    while ( (SPI_I2S_GetFlagStatus(SPI1, SPI_I2S_FLAG_RXNE) == RESET) && \
            (SPI_I2S_GetFlagStatus(SPI1, SPI_I2S_FLAG_BSY) == SET) );
    SPI_I2S_ReceiveData(SPI1);												

	while (SPI_I2S_GetFlagStatus(SPI1, SPI_I2S_FLAG_BSY) == SET);           
	GPIO_SetBits(NSS_Port, NSS_Pin);

	__enable_irq();
}

/** 
	@function
	Read radiomodule register via SPI
	@param address - register address
	@return register value 
*/
uint8_t rfm69_read(uint8_t address)
{
	uint8_t data = 0x00;

	__disable_irq();
	while (SPI_I2S_GetFlagStatus(SPI1, SPI_I2S_FLAG_BSY) == SET);           

	GPIO_ResetBits(NSS_Port, NSS_Pin);

    SPI_I2S_SendData(SPI1, (address));                                      
    while ( (SPI_I2S_GetFlagStatus(SPI1, SPI_I2S_FLAG_TXE) == RESET) && \
            (SPI_I2S_GetFlagStatus(SPI1, SPI_I2S_FLAG_BSY) == SET) );

    SPI_I2S_SendData(SPI1, 0x87);                                           

    while ( (SPI_I2S_GetFlagStatus(SPI1, SPI_I2S_FLAG_RXNE) == RESET) && \
            (SPI_I2S_GetFlagStatus(SPI1, SPI_I2S_FLAG_BSY) == SET) );
    SPI_I2S_ReceiveData(SPI1);                                              

    while ( (SPI_I2S_GetFlagStatus(SPI1, SPI_I2S_FLAG_RXNE) == RESET) && \
            (SPI_I2S_GetFlagStatus(SPI1, SPI_I2S_FLAG_BSY) == SET) );
    data = SPI_I2S_ReceiveData(SPI1);                                       

    while (SPI_I2S_GetFlagStatus(SPI1, SPI_I2S_FLAG_BSY) == SET);           
	GPIO_SetBits(NSS_Port, NSS_Pin);

	__enable_irq();
	return data;
}

/** 
	@function
	Burst access to registers. Writes an array of registers via SPI. Works bad,
	not recommended to use.
	@param address - initial address
	@param data - register array pointer
	@param ndata - number of registers
	\warning {because of rfm69 hardware bugs not recommended to use}	  
*/
void rfm69_write_burst(uint8_t address, uint8_t *data, uint8_t ndata)
{
	uint8_t i;

	__disable_irq();
	GPIO_ResetBits(NSS_Port, NSS_Pin);

    SPI_I2S_SendData(SPI1, (address | 0x80));

	for (i=0 ; i<ndata ; ++i)
	{
    	while (SPI_I2S_GetFlagStatus(SPI1, SPI_I2S_FLAG_TXE) == RESET);
		SPI_I2S_SendData(SPI1, data[i]);

    	while (SPI_I2S_GetFlagStatus(SPI1, SPI_I2S_FLAG_RXNE) == RESET);
    	SPI_I2S_ReceiveData(SPI1);
	}
    while (SPI_I2S_GetFlagStatus(SPI1, SPI_I2S_FLAG_RXNE) == RESET);
    SPI_I2S_ReceiveData(SPI1);

	while (SPI_I2S_GetFlagStatus(SPI1, SPI_I2S_FLAG_BSY) == SET);
	GPIO_SetBits(NSS_Port, NSS_Pin);
	__enable_irq();
}

/** 
	@function
	Burst access to registers. Reads an array of registers via SPI. Works bad,
	not recommended to use.
	@param address - initial address
	@param data - register array pointer
	@param ndata - number of registers
	\warning {because of rfm69 hardware bugs not recommended to use} 
*/
void rfm69_read_burst(uint8_t address, uint8_t *data, uint8_t ndata)
{
	uint8_t i;

	__disable_irq();
	GPIO_ResetBits(NSS_Port, NSS_Pin);

    SPI_I2S_SendData(SPI1, address);  

	while (SPI_I2S_GetFlagStatus(SPI1, SPI_I2S_FLAG_TXE) == RESET);
	SPI_I2S_SendData(SPI1, 0xff);

	while (SPI_I2S_GetFlagStatus(SPI1, SPI_I2S_FLAG_RXNE) == RESET);
	SPI_I2S_ReceiveData(SPI1);

	--ndata;
	for (i=0 ; i<ndata ; ++i)
	{
    	while (SPI_I2S_GetFlagStatus(SPI1, SPI_I2S_FLAG_TXE) == RESET);
		SPI_I2S_SendData(SPI1, 0xff);

    	while (SPI_I2S_GetFlagStatus(SPI1, SPI_I2S_FLAG_RXNE) == RESET);
    	data[i] = SPI_I2S_ReceiveData(SPI1);
	}
    while (SPI_I2S_GetFlagStatus(SPI1, SPI_I2S_FLAG_RXNE) == RESET);
    data[ndata] = SPI_I2S_ReceiveData(SPI1);

	while (SPI_I2S_GetFlagStatus(SPI1, SPI_I2S_FLAG_BSY) == SET);
	GPIO_SetBits(NSS_Port, NSS_Pin);
	__enable_irq();
}


/** 
	@function
	This function implements MCU initialisation, i.e. initialisaton of SPI 
	interface, interrupts, GPIOs, etc. 
*/
void rfm69_mcu_init(void)
{
//	Clock sources
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_SPI1, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_GPIOB, ENABLE);		

//	SPI initialisation 
	GPIO_InitTypeDef gpio;					// NSS pin configuration
	GPIO_StructInit(&gpio);
	gpio.GPIO_Pin = NSS_Pin;
	gpio.GPIO_Speed = GPIO_Speed_50MHz;
	gpio.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_Init(NSS_Port, &gpio);

	GPIO_StructInit(&gpio);					// configuration of MOSI and SCK pins
	gpio.GPIO_Pin = GPIO_Pin_7 | GPIO_Pin_5;
	gpio.GPIO_Speed = GPIO_Speed_50MHz;
	gpio.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_Init(GPIOA, &gpio);

	GPIO_StructInit(&gpio);					// MISO pin configuration
	gpio.GPIO_Pin = GPIO_Pin_6;
	gpio.GPIO_Speed = GPIO_Speed_50MHz;
	gpio.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_Init(GPIOA, &gpio);

	SPI_InitTypeDef spi;
	SPI_StructInit(&spi);
	spi.SPI_Direction = SPI_Direction_2Lines_FullDuplex;
	spi.SPI_Mode = SPI_Mode_Master;
	spi.SPI_DataSize = SPI_DataSize_8b;
	spi.SPI_CPOL = SPI_CPOL_Low;
	spi.SPI_CPHA = SPI_CPHA_1Edge;
	spi.SPI_NSS = SPI_NSS_Soft;
	spi.SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_16;
	spi.SPI_FirstBit = SPI_FirstBit_MSB;
	SPI_Init(SPI1, &spi);

	SPI_SSOutputCmd(SPI1, DISABLE);
	SPI_NSSInternalSoftwareConfig(SPI1, SPI_NSSInternalSoft_Set);
	GPIO_SetBits(NSS_Port, NSS_Pin);
	SPI_Cmd(SPI1, ENABLE);

//	External interrupt initialisation
	NVIC_EnableIRQ(EXTI0_IRQn);					// enable external interrupts
	NVIC_EnableIRQ(EXTI1_IRQn);
    NVIC_EnableIRQ(EXTI2_IRQn);

	EXTI_InitTypeDef exti_is;
	EXTI_StructInit(&exti_is);
	exti_is.EXTI_Line = CRCOK_PKSent_Line;
	exti_is.EXTI_Mode = EXTI_Mode_Interrupt;
	exti_is.EXTI_Trigger = EXTI_Trigger_Rising;
	exti_is.EXTI_LineCmd = ENABLE;
	EXTI_Init(&exti_is);

	exti_is.EXTI_Line = FifoLevel_Line;
	exti_is.EXTI_Mode = EXTI_Mode_Interrupt;
	exti_is.EXTI_Trigger = EXTI_Trigger_Rising;
	exti_is.EXTI_LineCmd = ENABLE;
	EXTI_Init(&exti_is);

	exti_is.EXTI_Line = SyncAddr_Line;
	exti_is.EXTI_Mode = EXTI_Mode_Interrupt;
	exti_is.EXTI_Trigger = EXTI_Trigger_Rising;
	exti_is.EXTI_LineCmd = ENABLE;
	EXTI_Init(&exti_is);

	GPIO_EXTILineConfig(EXTI_Port1, EXTI_Pin1);
	GPIO_EXTILineConfig(EXTI_Port23, EXTI_Pin2);
	GPIO_EXTILineConfig(EXTI_Port23, EXTI_Pin3);
}

/** 
	@function
	This function performs radiomodule initialisation. It writes radiomodule 
	register values via SPI, which were defined and calculated in file rfm69.h. 
	It also checks the SPI interface, if it doesn't work, it sets the @ref
	RFM69_SPI_FAILED state. 
	@return 0 if initialisation completed successfully, and -1 otherwise
*/
int rfm69_init(void)
{
	int j;

    rfm69_mcu_init();

//	RFM69 initialization
	rfm69_write(REGOPMODE, REGOPMODE_DEF | STBY_MODE);
	rfm69_write(REGDATAMODUL, REGDATAMODUL_DEF);

	rfm69_write(REGFDEVMSB, REGFDEVMSB_DEF);
	rfm69_write(REGFDEVLSB, REGFDEVLSB_DEF);

	rfm69_write(REGBITRATEMSB, REGBITRATEMSB_DEF);
	rfm69_write(REGBITRATELSB, REGBITRATELSB_DEF);

	rfm69_write(REGFRFMSB, REGFRFMSB_DEF);
	rfm69_write(REGFRFMID, REGFRFMID_DEF);
	rfm69_write(REGFRFLSB, REGFRFLSB_DEF);

	rfm69_write(REGAFCCTRL, REGAFCCTRL_DEF);

//	rfm69_write(REGLISTEN1, REGLISTEN1_DEF);
//	rfm69_write(REGLISTEN2, REGLISTEN2_DEF);
//	rfm69_write(REGLISTEN3, REGLISTEN3_DEF);

	rfm69_write(REGPALEVEL, REGPALEVEL_DEF);
	rfm69_write(REGPARAMP, REGPARAMP_DEF);
	rfm69_write(REGOCP, REGOCP_DEF);
	rfm69_write(REGLNA, REGLNA_DEF);

	rfm69_write(REGRXBW, REGRXBW_DEF);
	rfm69_write(REGAFCBW, REGAFCBW_DEF);

//	rfm69_write(REGOOKPEAK, REGOOKPEAK_DEF);
//	rfm69_write(REGOOKAVG, REGOOKAVG_DEF);
//	rfm69_write(REGOOKFIX, REGOOKFIX_DEF);

	rfm69_write(REGAFCFEI, REGAFCFEI_DEF);

	rfm69_write(REGDIOMAPPING1, REGDIOMAPPING1_DEF);
	rfm69_write(REGDIOMAPPING2, REGDIOMAPPING2_DEF);

	rfm69_write(REGRSSITHRESH, REGRSSITHRESH_DEF);

	rfm69_write(REGPREAMBLEMSB, REGPREAMBLEMSB_DEF);
	rfm69_write(REGPREAMBLELSB, REGPREAMBLELSB_DEF);

	rfm69_write(REGSYNCCONFIG, REGSYNCCONFIG_DEF);
	rfm69_write(REGSYNCVALUE1, REGSYNCVALUE1_DEF);
	rfm69_write(REGSYNCVALUE2, REGSYNCVALUE2_DEF);
	rfm69_write(REGSYNCVALUE3, REGSYNCVALUE3_DEF);
	rfm69_write(REGSYNCVALUE4, REGSYNCVALUE4_DEF);
	rfm69_write(REGSYNCVALUE5, REGSYNCVALUE5_DEF);
	rfm69_write(REGSYNCVALUE6, REGSYNCVALUE6_DEF);
	rfm69_write(REGSYNCVALUE7, REGSYNCVALUE7_DEF);
	rfm69_write(REGSYNCVALUE8, REGSYNCVALUE8_DEF);

	rfm69_write(REGPACKETCONFIG1, REGPACKETCONFIG1_DEF);
	rfm69_write(REGPAYLOADLENGHT, REGPAYLOADLENGHT_DEF);
	rfm69_write(REGNODEADRS, REGNODEADRS_DEF);
	rfm69_write(REGBROADCASTADRS, REGBROADCASTADRS_DEF);
	rfm69_write(REGAUTOMODES, REGAUTOMODES_DEF);

	rfm69_write(REGFIFOTHRES, REGFIFOTHRES_DEF);
	rfm69_write(REGPACKETCONFIG2, REGPACKETCONFIG2_DEF);

//	rfm69_write(REGAESKEY1, REGAESKEY1_DEF);
//	rfm69_write(REGAESKEY2, REGAESKEY2_DEF);
//	rfm69_write(REGAESKEY3, REGAESKEY3_DEF);
//	rfm69_write(REGAESKEY4, REGAESKEY4_DEF);
//	rfm69_write(REGAESKEY5, REGAESKEY5_DEF);
//	rfm69_write(REGAESKEY6, REGAESKEY6_DEF);
//	rfm69_write(REGAESKEY7, REGAESKEY7_DEF);
//	rfm69_write(REGAESKEY8, REGAESKEY8_DEF);
//	rfm69_write(REGAESKEY9, REGAESKEY9_DEF);
//	rfm69_write(REGAESKEY10, REGAESKEY10_DEF);
//	rfm69_write(REGAESKEY11, REGAESKEY11_DEF);
//	rfm69_write(REGAESKEY12, REGAESKEY12_DEF);
//	rfm69_write(REGAESKEY13, REGAESKEY13_DEF);
//	rfm69_write(REGAESKEY14, REGAESKEY14_DEF);
//	rfm69_write(REGAESKEY15, REGAESKEY15_DEF);
//	rfm69_write(REGAESKEY16, REGAESKEY16_DEF);

	rfm69_write(REGTESTDAGC, AFC_LOW_BETA_OFF);

	rfm69_write(REGIRQFLAGS2, 1<<FIFOOVERRUN);

	for (j=0 ; j<99999 ; ++j);
	rfm69_receive_start();

	if ( rfm69_read(REGRXBW) != REGRXBW_DEF ) {     // SPI check
		rfm69_condition = RFM69_SPI_FAILED;
		return -1;
	}
	else	return 0;
}

/** 
	@function
	Start packet transmittion. This function assumes that radiomodule is in receive, sleep or standby mode. Also do not forget to 
	switch the transmitter off when package is already transmitted (interrupts will do that).
	@param packet_size_loc - size of the packet
	@param address - destination address (use broadcast address 0xff if you do not know any)
	@return negative value if something wrong (package is too big, or SPI doesn't work), and return 0 if all is well
*/
int rfm69_transmit_start(uint8_t packet_size_loc, uint8_t address)
{
	int i;

	packet_size = packet_size_loc;
	if(packet_size > RFM69_BUFFER_SIZE)	return -1;							// check size of the package
	
	switch(rfm69_condition)
	{
		case RFM69_SPI_FAIL :
			return -1;
		case RFM69_SLEEP :
			rfm69_fifo_clear();
			break;
		case RFM69_STBY :
			rfm69_fifo_clear();
			break;
		case RFM69_RX :
			break;
		case RFM69_TX :
			return -1;
	}
	
	rfm69_condition = RFM69_TX;
	rfm69_write(REGOPMODE, REGOPMODE_DEF | TX_MODE);                        // makes transmitter on

	rfm69_write(REGFIFO, packet_size+1);									// transmit the packet size into FIFO
	rfm69_write(REGFIFO, address);											// transmit address into FIFO
	for(i=0 ; i<packet_size ; ++i)	rfm69_write(REGFIFO, packet_buffer[i]);	// transmit packet payload into FIFO

	return 0;
}

/** 
	@function
	Switch radiomodule into receiver mode.
*/
void rfm69_receive_start(void)
{
	rfm69_condition = RFM69_RX;
	rfm69_write(REGOPMODE, REGOPMODE_DEF | RX_MODE);
}

/** 
	@function
	This function reads received packet into the @ref packet_buffer
	@return size of the received packet, and if size of the received package exceeded the buffer size, return -1
*/
int rfm69_receive_small_packet(void)
{
	int i;

	packet_size = rfm69_read(REGFIFO);										// read the packet size
	if(packet_size > RFM69_BUFFER_SIZE)	return -1;							// check size of the package

	rfm69_read(REGFIFO);													// drop address
	--packet_size;

	for(i=0 ; i<packet_size ; ++i) packet_buffer[i] = rfm69_read(REGFIFO);	// read package from FIFO
	rfm69_clear_fifo(void);

	return packet_size;
}

/**
	@function
	Switch radiomodule into sleep mode.
*/
void rfm69_sleep(void)
{
	rfm69_write(REGOPMODE, REGOPMODE_DEF | SLEEP_MODE);
	rfm69_condition = RFM69_SLEEP;
}

/**
	@function
	Switch radiomodule into standby mode.
*/
void rfm69_stby(void)
{
	rfm69_write(REGOPMODE, REGOPMODE_DEF | STBY_MODE);
	rfm69_condition = RFM69_STBY;
}

/**
	@function
	Clear FIFO of radiomodule.
*/
void rfm69_clear_fifo(void)
{
    int i;
    for(i=0 ; i<RFM69_BUFFER_SIZE ; ++i)   rfm69_read(REGFIFO);		// read every register one by one
    rfm69_write(REGIRQFLAGS2, 1<<FIFOOVERRUN);						// clear flag if overrun
}
