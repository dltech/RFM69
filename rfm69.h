#ifndef RFM69_H_INCLUDED
#define RFM69_H_INCLUDED

/* Основные настройки (можно менять только их, при условии что остальные не тронуты) */




/* Константы */

#define FXOSC	32000000.
#define	FSTEP	61.

#define

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

#define	BITRATE_CALC(FXOSC/br_par)	br_par

#define	REGFDEVMSB			0x05
#define	REGFDEVLSB			0x06

#define	FDEV_CALC(fdev_par/FSTEP)	fdev_par

#define	REGFRFMSB			0x07
#define	REGFRFMID			0x08
#define	REGFRFLSB			0x09

#define FRF_CALC(frf_par/FSTEP)		frf_calc

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

#define	REGOCP				0x13

#define	OCPON			4

#define	OCP_CURRENT_CALC(0x0f&((ocp_param/5) - 9))	ocp_param

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
