#ifndef RFM69_H_INCLUDED
#define RFM69_H_INCLUDED

/* Основные настройки (можно менять только их, при условии что остальные не тронуты) */

#define RX_BW				200			// bandwidth of the channel filter in kHz, must be at least twice bigger then bitrate
#define RX_BW_AFC			200			// bandwidth of the channel filter in kHz, must be at least twice bigger then bitrate

#define	CUT_OFF_FREQ		4			// cut off frecuency of the DC canceller exprecced in % of RXBW
#define	CUT_OFF_FREQ_AFC	4			// cut off frecuency of the DC canceller exprecced in % of RXBW

/// FSK parametres
#define FSK_ON				1
#define RISE_FALL_TIME_FSK	3400		//  rise/fall time of ramp up/down in FSK in us (from 10 to 3400)

/// OOK parametres

// for peak demodulator
#define	OOK_PEAK_THRES_STEP	1			// size of each decrement of the RSSI threshold in the OOK demodulator in dB (from 0.5 to 6.0)
#define OOK_PEAK_THRESH_DEC	1			// period of decrement of the RSSI threshold in the OOK demodulator exprecced in times per cheap (from 0.125 to 16)

// for fixed threshold demodulator
#define	OOKFIXEDTHRESH		6			// theshold value in dB 

/* Константы */

#define FXOSC	32000000.
#define	FSTEP	61.

#define	PI		3.14159265359

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

#define	BITRATE_CALC(br_par)	(br_par)/FXOSC

#define	REGFDEVMSB			0x05
#define	REGFDEVLSB			0x06

#define	FDEV_CALC(fdev_par)		(fdev_par)/FSTEP

#define	REGFRFMSB			0x07
#define	REGFRFMID			0x08
#define	REGFRFLSB			0x09

#define FRF_CALC(frf_par)		(frf_par)/FSTEP

#define	REGOSC1				0x0a

#define	RCCALSTART		7
#define	RCCALDONE		6

#define	REGAFCCTRL			0x0b

#define	AFCLOWBETAON	5

#define	REGLISTEN1			0x0d

#define	LISTENIDLE262M	0xc0
#define	LISTENIDLE4M1	0x80
#define	LISTENIDLE64U	0x40

#define	LISTENRX262M	0x30
#define	LISTENRX4M1		0x20
#define	LISTENRX64U		0x10

#define	LISTENCRITERIA	3

#define	LISTENEND1		0x00
#define	LISTENEND2		0x02
#define	LISTENEND3		0x04
#define	LISTENEND4		0x06

#define	REGLISTEN2			0x0e
#define	REGLISTEN3			0x0f	
#define	REGVERSION			0x10

#define	REGPALEVEL			0x11

#define PA0ON			7			// if 1 - power amplifier 0 on
#define PA1ON			6			// if 1 - power amplifier 1 on
#define PA2ON			5			// if 1 - power amplifier 2 on

#define	OUT_POWER_CALC(0x1f&(18 - power_par))	power_par

#define	REGPARAMP			0x12

#if (RISE_FALL_TIME_FSK >= 2000)
    #define PARAMP 0x01
#elif (RISE_FALL_TIME_FSK >= 1000)
    #define PARAMP 0x02
#elif (RISE_FALL_TIME_FSK >= 500)
    #define PARAMP 0x03
#elif (RISE_FALL_TIME_FSK >= 250)
    #define PARAMP 0x04
#elif (RISE_FALL_TIME_FSK >= 125)
    #define PARAMP 0x05
#elif (RISE_FALL_TIME_FSK >= 100)
    #define PARAMP 0x06
#elif (RISE_FALL_TIME_FSK >= 62)
    #define PARAMP 0x07
#elif (RISE_FALL_TIME_FSK >= 50)
    #define PARAMP 0x08
#elif (RISE_FALL_TIME_FSK >= 40)
    #define PARAMP 0x09
#elif (RISE_FALL_TIME_FSK >= 31)
    #define PARAMP 0x0a
#elif (RISE_FALL_TIME_FSK >= 25)
    #define PARAMP 0x0b
#elif (RISE_FALL_TIME_FSK >= 20)
    #define PARAMP 0x0c
#elif (RISE_FALL_TIME_FSK >= 15)
    #define PARAMP 0x0d
#elif (RISE_FALL_TIME_FSK >= 12)
    #define PARAMP 0x0e
#elif (RISE_FALL_TIME_FSK >= 10)
    #define PARAMP 0x0f
#else
    #define PARAMP 0x00
#endif

#define	REGOCP				0x13

#define	OCPON			4

#define	OCP_CURRENT_CALC(ocp_param)	0x0f&(((ocp_param)/5) - 9)

#define	REGLNA				0x18

#define	LNAZIN			7

#define	LNAGAIN_AUTO	0x00
#define	LNAGAIN_0DB		0x01
#define	LNAGAIN_6DB		0x02
#define	LNAGAIN_12DB	0x03
#define	LNAGAIN_24DB	0x04
#define	LNAGAIN_36DB	0x05
#define	LNAGAIN_48DB	0x06

#define	REGRXBW				0x19

#if (CUT_OFF_FREQ >= 16)
    #define DCCFREQ 0x00
#elif (CUT_OFF_FREQ >= 8)
    #define DCCFREQ 0x20
#elif (CUT_OFF_FREQ >= 4)
    #define DCCFREQ 0x40
#elif (CUT_OFF_FREQ >= 2)
    #define DCCFREQ 0x60
#elif (CUT_OFF_FREQ >= 1)
    #define DCCFREQ 0x80
#elif (CUT_OFF_FREQ >= 0.5)
    #define DCCFREQ 0xa0
#elif (CUT_OFF_FREQ >= 0.25)
    #define DCCFREQ 0xc0
#elif (CUT_OFF_FREQ >= 0.125)
    #define DCCFREQ 0xe0
#endif

#if ((RX_BW >= 500.0) && (FSK_ON > 0))
    #define RXBW 0x00
#elif ((RX_BW >= 400.0) && (FSK_ON > 0))
    #define RXBW 0x08
#elif ((RX_BW >= 333.3) && (FSK_ON > 0))
    #define RXBW 0x10
#elif ((RX_BW >= 250.0) && (FSK_ON > 0))
    #define RXBW 0x01
#elif ((RX_BW >= 200.0) && (FSK_ON > 0))
    #define RXBW 0x09
#elif ((RX_BW >= 166.7) && (FSK_ON > 0))
    #define RXBW 0x11
#elif ((RX_BW >= 125.0) && (FSK_ON > 0))
    #define RXBW 0x02
#elif ((RX_BW >= 100.0) && (FSK_ON > 0))
    #define RXBW 0x0a
#elif ((RX_BW >= 83.3) && (FSK_ON > 0))
    #define RXBW 0x12
#elif ((RX_BW >= 62.5) && (FSK_ON > 0))
    #define RXBW 0x03
#elif ((RX_BW >= 50.0) && (FSK_ON > 0))
    #define RXBW 0x0b
#elif ((RX_BW >= 41.7) && (FSK_ON > 0))
    #define RXBW 0x13
#elif ((RX_BW >= 31.3) && (FSK_ON > 0))
    #define RXBW 0x04
#elif ((RX_BW >= 25.0) && (FSK_ON > 0))
    #define RXBW 0x0c
#elif ((RX_BW >= 20.8) && (FSK_ON > 0))
    #define RXBW 0x14
#elif ((RX_BW >= 15.6) && (FSK_ON > 0))
    #define RXBW 0x05
#elif ((RX_BW >= 12.5) && (FSK_ON > 0))
    #define RXBW 0x0d
#elif ((RX_BW >= 10.4) && (FSK_ON > 0))
    #define RXBW 0x15
#elif ((RX_BW >= 7.8) && (FSK_ON > 0))
    #define RXBW 0x06
#elif ((RX_BW >= 6.3) && (FSK_ON > 0))
    #define RXBW 0x0e
#elif ((RX_BW >= 5.2) && (FSK_ON > 0))
    #define RXBW 0x16
#elif ((RX_BW >= 3.9) && (FSK_ON > 0))
    #define RXBW 0x07
#elif ((RX_BW >= 3.1) && (FSK_ON > 0))
    #define RXBW 0x0f
#elif ((RX_BW >= 2.6) && (FSK_ON > 0))
    #define RXBW 0x17
#endif

#if ((RX_BW >= 250.0) && (OOK_ON > 0))
    #define RXBW 0x00
#elif ((RX_BW >= 200.0) && (OOK_ON > 0))
    #define RXBW 0x08
#elif ((RX_BW >= 166.7) && (OOK_ON > 0))
    #define RXBW 0x10
#elif ((RX_BW >= 125.0) && (OOK_ON > 0))
    #define RXBW 0x01
#elif ((RX_BW >= 100.0) && (OOK_ON > 0))
    #define RXBW 0x09
#elif ((RX_BW >= 83.3) && (OOK_ON > 0))
    #define RXBW 0x11
#elif ((RX_BW >= 62.5) && (OOK_ON > 0))
    #define RXBW 0x02
#elif ((RX_BW >= 50.0) && (OOK_ON > 0))
    #define RXBW 0x0a
#elif ((RX_BW >= 41.7) && (OOK_ON > 0))
    #define RXBW 0x12
#elif ((RX_BW >= 31.3) && (OOK_ON > 0))
    #define RXBW 0x03
#elif ((RX_BW >= 25.0) && (OOK_ON > 0))
    #define RXBW 0x0b
#elif ((RX_BW >= 20.8) && (OOK_ON > 0))
    #define RXBW 0x13
#elif ((RX_BW >= 15.6) && (OOK_ON > 0))
    #define RXBW 0x04
#elif ((RX_BW >= 12.5) && (OOK_ON > 0))
    #define RXBW 0x0c
#elif ((RX_BW >= 10.4) && (OOK_ON > 0))
    #define RXBW 0x14
#elif ((RX_BW >= 7.8) && (OOK_ON > 0))
    #define RXBW 0x05
#elif ((RX_BW >= 6.3) && (OOK_ON > 0))
    #define RXBW 0x0d
#elif ((RX_BW >= 5.2) && (OOK_ON > 0))
    #define RXBW 0x15
#elif ((RX_BW >= 3.9) && (OOK_ON > 0))
    #define RXBW 0x06
#elif ((RX_BW >= 3.1) && (OOK_ON > 0))
    #define RXBW 0x0e
#elif ((RX_BW >= 2.6) && (OOK_ON > 0))
    #define RXBW 0x16
#elif ((RX_BW >= 2.0) && (OOK_ON > 0))
    #define RXBW 0x07
#elif ((RX_BW >= 1.6) && (OOK_ON > 0))
    #define RXBW 0x0f
#elif ((RX_BW >= 1.3) && (OOK_ON > 0))
    #define RXBW 0x17
#endif

#define	REGAFCBW			0x1a

#if (CUT_OFF_FREQ_AFC >= 16)
    #define DCCFREQAFC 0x00
#elif (CUT_OFF_FREQ_AFC >= 8)
    #define DCCFREQAFC 0x20
#elif (CUT_OFF_FREQ_AFC >= 4)
    #define DCCFREQAFC 0x40
#elif (CUT_OFF_FREQ_AFC >= 2)
    #define DCCFREQAFC 0x60
#elif (CUT_OFF_FREQ_AFC >= 1)
    #define DCCFREQAFC 0x80
#elif (CUT_OFF_FREQ_AFC >= 0.5)
    #define DCCFREQAFC 0xa0
#elif (CUT_OFF_FREQ_AFC >= 0.25)
    #define DCCFREQAFC 0xc0
#elif (CUT_OFF_FREQ_AFC >= 0.125)
    #define DCCFREQAFC 0xe0
#endif

#if ((RX_BW_AFC >= 500.0) && (FSK_ON > 0))
    #define RXBWAFC 0x00
#elif ((RX_BW_AFC >= 400.0) && (FSK_ON > 0))
    #define RXBWAFC 0x08
#elif ((RX_BW_AFC >= 333.3) && (FSK_ON > 0))
    #define RXBWAFC 0x10
#elif ((RX_BW_AFC >= 250.0) && (FSK_ON > 0))
    #define RXBWAFC 0x01
#elif ((RX_BW_AFC >= 200.0) && (FSK_ON > 0))
    #define RXBWAFC 0x09
#elif ((RX_BW >= 166.7) && (FSK_ON > 0))
    #define RXBWAFC 0x11
#elif ((RX_BW >= 125.0) && (FSK_ON > 0))
    #define RXBWAFC 0x02
#elif ((RX_BW >= 100.0) && (FSK_ON > 0))
    #define RXBWAFC 0x0a
#elif ((RX_BW >= 83.3) && (FSK_ON > 0))
    #define RXBWAFC 0x12
#elif ((RX_BW >= 62.5) && (FSK_ON > 0))
    #define RXBWAFC 0x03
#elif ((RX_BW >= 50.0) && (FSK_ON > 0))
    #define RXBWAFC 0x0b
#elif ((RX_BW >= 41.7) && (FSK_ON > 0))
    #define RXBWAFC 0x13
#elif ((RX_BW >= 31.3) && (FSK_ON > 0))
    #define RXBWAFC 0x04
#elif ((RX_BW >= 25.0) && (FSK_ON > 0))
    #define RXBWAFC 0x0c
#elif ((RX_BW >= 20.8) && (FSK_ON > 0))
    #define RXBWAFC 0x14
#elif ((RX_BW >= 15.6) && (FSK_ON > 0))
    #define RXBWAFC 0x05
#elif ((RX_BW >= 12.5) && (FSK_ON > 0))
    #define RXBWAFC 0x0d
#elif ((RX_BW >= 10.4) && (FSK_ON > 0))
    #define RXBWAFC 0x15
#elif ((RX_BW >= 7.8) && (FSK_ON > 0))
    #define RXBWAFC 0x06
#elif ((RX_BW >= 6.3) && (FSK_ON > 0))
    #define RXBWAFC 0x0e
#elif ((RX_BW >= 5.2) && (FSK_ON > 0))
    #define RXBWAFC 0x16
#elif ((RX_BW >= 3.9) && (FSK_ON > 0))
    #define RXBWAFC 0x07
#elif ((RX_BW >= 3.1) && (FSK_ON > 0))
    #define RXBWAFC 0x0f
#elif ((RX_BW >= 2.6) && (FSK_ON > 0))
    #define RXBWAFC 0x17
#endif

#if ((RX_BW >= 250.0) && (OOK_ON > 0))
    #define RXBWAFC 0x00
#elif ((RX_BW >= 200.0) && (OOK_ON > 0))
    #define RXBWAFC 0x08
#elif ((RX_BW >= 166.7) && (OOK_ON > 0))
    #define RXBWAFC 0x10
#elif ((RX_BW >= 125.0) && (OOK_ON > 0))
    #define RXBWAFC 0x01
#elif ((RX_BW >= 100.0) && (OOK_ON > 0))
    #define RXBWAFC 0x09
#elif ((RX_BW >= 83.3) && (OOK_ON > 0))
    #define RXBWAFC 0x11
#elif ((RX_BW >= 62.5) && (OOK_ON > 0))
    #define RXBWAFC 0x02
#elif ((RX_BW >= 50.0) && (OOK_ON > 0))
    #define RXBWAFC 0x0a
#elif ((RX_BW >= 41.7) && (OOK_ON > 0))
    #define RXBWAFC 0x12
#elif ((RX_BW >= 31.3) && (OOK_ON > 0))
    #define RXBWAFC 0x03
#elif ((RX_BW >= 25.0) && (OOK_ON > 0))
    #define RXBWAFC 0x0b
#elif ((RX_BW >= 20.8) && (OOK_ON > 0))
    #define RXBWAFC 0x13
#elif ((RX_BW >= 15.6) && (OOK_ON > 0))
    #define RXBWAFC 0x04
#elif ((RX_BW >= 12.5) && (OOK_ON > 0))
    #define RXBWAFC 0x0c
#elif ((RX_BW >= 10.4) && (OOK_ON > 0))
    #define RXBWAFC 0x14
#elif ((RX_BW >= 7.8) && (OOK_ON > 0))
    #define RXBWAFC 0x05
#elif ((RX_BW >= 6.3) && (OOK_ON > 0))
    #define RXBWAFC 0x0d
#elif ((RX_BW >= 5.2) && (OOK_ON > 0))
    #define RXBWAFC 0x15
#elif ((RX_BW >= 3.9) && (OOK_ON > 0))
    #define RXBWAFC 0x06
#elif ((RX_BW >= 3.1) && (OOK_ON > 0))
    #define RXBWAFC 0x0e
#elif ((RX_BW >= 2.6) && (OOK_ON > 0))
    #define RXBWAFC 0x16
#elif ((RX_BW >= 2.0) && (OOK_ON > 0))
    #define RXBWAFC 0x07
#elif ((RX_BW >= 1.6) && (OOK_ON > 0))
    #define RXBWAFC 0x0f
#elif ((RX_BW >= 1.3) && (OOK_ON > 0))
    #define RXBW 0x17
#endif

#define	REGOOKPEAK			0x1b

#define	OOKTHRESFIXED	0x00
#define	OOKTHRESPEAK	0x40
#define	OOKTHRESAVERAGE	0x80

#if (OOK_PEAK_THRESH_STEP >= 6.0)
	#define	OOKPEAKTHRESHSTEP	0x38
#elif (OOK_PEAK_THRESH_STEP >= 5.0)
	#define	OOKPEAKTHRESHSTEP	0x30
#elif (OOK_PEAK_THRESH_STEP >= 4.0)
	#define	OOKPEAKTHRESHSTEP	0x28
#elif (OOK_PEAK_THRESH_STEP >= 3.0)
	#define	OOKPEAKTHRESHSTEP	0x20
#elif (OOK_PEAK_THRESH_STEP >= 2.0)
	#define	OOKPEAKTHRESHSTEP	0x18
#elif (OOK_PEAK_THRESH_STEP >= 1.5)
	#define	OOKPEAKTHRESHSTEP	0x10
#elif (OOK_PEAK_THRESH_STEP >= 1.0)
	#define	OOKPEAKTHRESHSTEP	0x08
#elif (OOK_PEAK_THRESH_STEP >= 0.5)
	#define	OOKPEAKTHRESHSTEP	0x00
#endif

#if (OOK_PEAK_THRESH_DEC >= 16)
	#define	OOKPEAKTHRESHDEC	0x07
#elif (OOK_PEAK_THRESH_DEC >= 8)
	#define OOKPEAKTHRESHDEC	0x06
#elif (OOK_PEAK_THRESH_DEC >= 4)
	#define OOKPEAKTHRESHDEC	0x05
#elif (OOK_PEAK_THRESH_DEC >= 2)
	#define OOKPEAKTHRESHDEC	0x04
#elif (OOK_PEAK_THRESH_DEC >= 1)
	#define OOKPEAKTHRESHDEC	0x00
#elif (OOK_PEAK_THRESH_DEC >= 0.5)
	#define OOKPEAKTHRESHDEC	0x01
#elif (OOK_PEAK_THRESH_DEC >= 0.25)
	#define OOKPEAKTHRESHDEC	0x02
#elif (OOK_PEAK_THRESH_DEC >= 0.125)
	#define OOKPEAKTHRESHDEC	0x03
#endif

#define	REGOOKAVG			0x1c // лень заполнять
#define	REGOOKFIX			0x1d

#define	REGAFCFEI			0x1e

#define	FEIDONE			6		// 0 - frequency error indicator is on-going, 1 - FEI is finished 
#define	FEISTART		5		// write 1 to start FEI
#define	AFCDONE			4		// 0 - AFC is on-going, 1 - AFC is finished
#define	AFCAUTOCLEAR	3		// 0 - AFC auto clear off, 1 - auto clear on
#define	AFCAUTOON		2		// 0 - AFC auto mode off, 1 - on
#define	AFCCLEAR		1		// write 1 to clear AFC value
#define	AFCSTART		0		// write 1 to start AFC

#define	REGAFCMSB			0x1f
#define	REGAFCLSB			0x20

#define	AFC_VALUE(afc_par)	(afc_par)*FSTEP

#define	REGFEIMSB			0x21
#define	REGFEILSB			0x22

#define	FEI_VALUE(fei_par)	(fei_par)*FSTEP

#define	REGRSSICONFIG		0x23

#define	RSSIDONE		1		// 0 - RSSI is on-going, 1 - RSSI is done
#define	RSSISTART		0		// write 1 to start RSSI measurement

#define	REGRSSIVALUE		0x24

#define RSSI_VALUE(rssi_par)	(rssi_par)/2	// macro to calculate RSSI value in dBm from register value

#define	REGDIOMAPPING1		0x25
#define	REGDIOMAPPING2		0x26

#define CLKOUT32M	0x00
#define CLKOUT16M	0x01
#define CLKOUT8M	0x02
#define CLKOUT4M	0x03
#define CLKOUT2M	0x04
#define CLKOUT1M	0x05
#define CLKOUT_RC	0x06
#define CLKOUT_OFF	0x07

#define	REGIRQFLAGS1		0x27

#define	MODEREADY		7
#define	RXREADY			6
#define	TXREADY			5
#define	PLLLOCK			4
#define	RSSI_I			3
#define	TIMEOUT			2
#define	AUTOMODE		1
#define	SYNCADDRMATCH	0

#define	REGIRQFLAGS2		0x28

#define	FIFOISFULL		7
#define	FIFONOTEMPTY	6
#define	FIFOLEVEL		5
#define	FIFOOVERRUN		4
#define	PACKETSENT		3
#define	PAYLOADREADY	2
#define	CRCOK			1

#define	REGRSSITHRESH		0x29

#define RSSI_THRES_CALC(rssi_parr)	(rssi_parr)*2

#define	REGRXTIMEOUT1		0x2a
#define	REGRXTIMEOUT2		0x2b
#define	REGPREAMBLEMSB		0x2c
#define	REGPREAMBLELSB		0x2d

#define	REGSYNCCONSIG		0x2e

#define	SYNCON			7	// 1 - sync word on , 0 - sync word off
#define	


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

#define	TEMPMEASSTART	3	// write 1 to start temperature measurement
#define	TEMPMEASRUNNING	2	// 1 - if temperature measurement is on-going, 0 - if complete

#define	REGTEMP2			0x4f
/// test registers
#define	RETESTLNA			0x58

#define NORMAL_SENS_BOOST_MODE	0x1b
#define	HIGH_SENS_BOOST_MODE	0x2d

#define	REGTESTPA1			0x5a

#define	PA1_NORMAL_RX_MODE		0x55
#define	PA1_13DBM_RX_MODE		0x5d
#define	PA1_PA0_OR_RX			0x55

#define	REGTESTPA2			0x5c

#define	PA2_NORMAL_RX_MODE		0x55
#define	PA2_13DBM_RX_MODE		0x5d
#define	PA2_PA0_OR_RX			0x55

#define	REGTESTDAGC			0x6f

#define	AFC_NORMAL_MODE			0x00
#define	AFC_LOW_BETA_ON			0x20
#define	AFC_LOW_BETA_OFF		0x30

#define	REGTESTAFC			0x71

#define LOW_BETA_AFC_OFFSET_CALC(afcoff_par)	(afcoff_par)*448	// macro to calculate afc offset value for low modulation index systems in Hz from register value

/* Конфигурация регистров */










#endif // RFM69_H_INCLUDED




/* хрень


#define	PARAMPTIME3MS	0
#define	PARAMPTIME2MS	1
#define	PARAMPTIME1MS	2
#define	PARAMPTIME500US	3
#define	PARAMPTIME250US	4
#define	PARAMPTIME125US	5
#define	PARAMPTIME100US	6
#define	PARAMPTIME62US	7
#define	PARAMPTIME50US	8
#define	PARAMPTIME40US	9
#define	PARAMPTIME31US	10
#define	PARAMPTIME25US	11
#define	PARAMPTIME20US	12
#define	PARAMPTIME15US	13
#define	PARAMPTIME12US	14
#define	PARAMPTIME10US	15



*/



