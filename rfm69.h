#ifndef RFM69_H_INCLUDED
#define RFM69_H_INCLUDED

/* Основные настройки (можно менять только их, при условии что остальные не тронуты) */







/* Указатели регистров и описанине битов */

#define	REGFIFO				0x00
#define	REGOPMODE			0x01

#define SEQUENCEROFF	7
#define	LISTENON		6
#define	LISTENABORT		5

#define	RX_MODE			0x10
#define	TX_MODE			0x0c
#define	FS_MODE			0x08
#define	STBY_MODE		0x04
#define	SLEEP_MODE		0x00

#define	REGDATAMODUL		0x02
		
#define	CONT_MODE		0x60
#define	CONT_SYNCH_MODE	0x40
#define	PACKET_MODE		0x00

#define	OOK				0x08
#define	FSK				0x00

#define	GAUSS_BT03		0x03
#define	GAUSS_BT05		0x02
#define	GAUSS_BT10		0x01
#define	NO_SHAPING		0x00		

#define	REBITRATEMSB		0x03
#define	REBITRATELSB		0x04

#define	BITRATE(br_par

#define	REGFDEVMSB			0x05
#define	REGFDEVLSB			0x06
#define	REGFRFMSB			0x07
#define	REGFRFMID			0x08
#define	REGFRFLSB			0x09
#define	REGOSC1				0x0a
#define	REGAFCCTRL			0x0b
#define	REGLISTEN1			0x0d
#define	REGLISTEN2			0x0e
#define	REGLISTEN3			0x0f	
#define	REGVERSION			0x10
#define	REGPALEVEL			0x11
#define	REGPARAMP			0x12
#define	REGOCP				0x13
#define	REGLNA				0x18	
#define	REGRXBW				0x19
#define	REGAFCBW			0x1a
#define	REGOOKPEAK			0x1b
#define	REGOOKAVG			0x1c
#define	REGOOKFIX			0x1d
#define	REGAFCFEI			0x1e
#define	REGAFCMSB			0x1f
#define	REGAFCLSB			0x20
#define	REGFEIMSB			0x21
#define	REGFEILSB			0x22
#define	REGRSSICONFIG		0x23
#define	REGRSSIVALUE		0x24
#define	REGDIOMAPPING1		0x25
#define	REGDIOMAPPING2		0x26
#define	REGIRQFLAGS1		0x27
#define	REGIRQFLAGS2		0x28
#define	REGRSSITHRESH		0x29	
#define	REGRXTIMEOUT1		0x2a
#define	REGRXTIMEOUT2		0x2b
#define	REGPREAMBLEMSB		0x2c
#define	REGPREAMBLELSB		0x2d
#define	REGSYNCCONSIG		0x2e
#define	REGSYNCVALUE1		0x2f
#define	REGSYNCVALUE2		0x30
#define	REGSYNCVALUE3		0x31
#define	REGSYNCVALUE4		0x32
#define	REGSYNCVALUE5		0x33
#define	REGSYNCVALUE6		0x34
#define	REGSYNCVALUE7		0x35
#define	REGSYNCVALUE8		0x36
#define REGPACKETCONFIG1	0x37
#define	REGPAYLOADLENGHT	0x38
#define	REGNODEADRS			0x39
#define	REGBROADCASTADRS	0x3a
#define	REGAUTOMODES		0x3b
#define	REGFIFOTHRES		0x3c
#define	REGPACKETCONFIG2	0x3d
#define	REGAESKEY1			0x3e
#define	REGAESKEY2			0x3f
#define	REGAESKEY3			0x40
#define	REGAESKEY4			0x41
#define	REGAESKEY5			0x42
#define	REGAESKEY6			0x43
#define	REGAESKEY7			0x44
#define	REGAESKEY8			0x45
#define	REGAESKEY9			0x46
#define	REGAESKEY10			0x47
#define	REGAESKEY11			0x48
#define	REGAESKEY12			0x49
#define	REGAESKEY13			0x4a
#define	REGAESKEY14			0x4b
#define	REGAESKEY15			0x4c
#define	REGAESKEY16			0x4d
#define	REGTEMP1			0x4e
#define	REGTEMP2			0x4f
#define	RETESTLNA			0x58
#define	REGTESTPA1			0x5a
#define	REGTESTPA2			0x5c
#define	REGTESTDAGC			0x6f
#define	REGTESTAFC			0x71

/* Конфигурация регистров */










#endif // RFM69_H_INCLUDED
