#ifndef RFM69_TABLE_H_INCLUDED
#define RFM69_TABLE_H_INCLUDED

/** @file rfm69_table.h @brief
	This file contains tables, which used for calculation of necessary parameters of radio module.
*/ 

// table for	REGPARAMP			0x12

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

// table for	REGRXBW				0x19

#define CUT_OFF_FREQ_M100	CUT_OFF_FREQ*100

#if (CUT_OFF_FREQ_M100 >= 1600)
    #define DCCFREQ 0x00
#elif (CUT_OFF_FREQ_M100 >= 800)
    #define DCCFREQ 0x20
#elif (CUT_OFF_FREQ_M100 >= 400)
    #define DCCFREQ 0x40
#elif (CUT_OFF_FREQ_M100 >= 200)
    #define DCCFREQ 0x60
#elif (CUT_OFF_FREQ_M100 >= 100)
    #define DCCFREQ 0x80
#elif (CUT_OFF_FREQ_M100 >= 50)
    #define DCCFREQ 0xa0
#elif (CUT_OFF_FREQ_M100 >= 25)
    #define DCCFREQ 0xc0
#elif (CUT_OFF_FREQ_M100 >= 13)
    #define DCCFREQ 0xe0
#endif

#define	RX_BW_M10	RX_BW*10

#if ((RX_BW_M10 >= 5000) && (MODUL_TYPE == FSK))
    #define RXBW 0x00
#elif ((RX_BW_M10 >= 4000) && (MODUL_TYPE == FSK))
    #define RXBW 0x08
#elif ((RX_BW_M10 >= 3333) && (MODUL_TYPE == FSK))
    #define RXBW 0x10
#elif ((RX_BW_M10 >= 2500) && (MODUL_TYPE == FSK))
    #define RXBW 0x01
#elif ((RX_BW_M10 >= 2000) && (MODUL_TYPE == FSK))
    #define RXBW 0x09
#elif ((RX_BW_M10 >= 1667) && (MODUL_TYPE == FSK))
    #define RXBW 0x11
#elif ((RX_BW_M10 >= 1250) && (MODUL_TYPE == FSK))
    #define RXBW 0x02
#elif ((RX_BW_M10 >= 1000) && (MODUL_TYPE == FSK))
    #define RXBW 0x0a
#elif ((RX_BW_M10 >= 833) && (MODUL_TYPE == FSK))
    #define RXBW 0x12
#elif ((RX_BW_M10 >= 625) && (MODUL_TYPE == FSK))
    #define RXBW 0x03
#elif ((RX_BW_M10 >= 500) && (MODUL_TYPE == FSK))
    #define RXBW 0x0b
#elif ((RX_BW_M10 >= 417) && (MODUL_TYPE == FSK))
    #define RXBW 0x13
#elif ((RX_BW_M10 >= 313) && (MODUL_TYPE == FSK))
    #define RXBW 0x04
#elif ((RX_BW_M10 >= 250) && (MODUL_TYPE == FSK))
    #define RXBW 0x0c
#elif ((RX_BW_M10 >= 208) && (MODUL_TYPE == FSK))
    #define RXBW 0x14
#elif ((RX_BW_M10 >= 156) && (MODUL_TYPE == FSK))
    #define RXBW 0x05
#elif ((RX_BW_M10 >= 125) && (MODUL_TYPE == FSK))
    #define RXBW 0x0d
#elif ((RX_BW_M10 >= 104) && (MODUL_TYPE == FSK))
    #define RXBW 0x15
#elif ((RX_BW_M10 >= 78) && (MODUL_TYPE == FSK))
    #define RXBW 0x06
#elif ((RX_BW_M10 >= 63) && (MODUL_TYPE == FSK))
    #define RXBW 0x0e
#elif ((RX_BW_M10 >= 52) && (MODUL_TYPE == FSK))
    #define RXBW 0x16
#elif ((RX_BW_M10 >= 39) && (MODUL_TYPE == FSK))
    #define RXBW 0x07
#elif ((RX_BW_M10 >= 31) && (MODUL_TYPE == FSK))
    #define RXBW 0x0f
#elif ((RX_BW_M10 >= 26) && (MODUL_TYPE == FSK))
    #define RXBW 0x17
#else
    #define RXBW 0x17
#endif

#if ((RX_BW_M10 >= 2500) && (MODUL_TYPE == OOK))
    #define RXBW 0x00
#elif ((RX_BW_M10 >= 2000) && (MODUL_TYPE == OOK))
    #define RXBW 0x08
#elif ((RX_BW_M10 >= 1667) && (MODUL_TYPE == OOK))
    #define RXBW 0x10
#elif ((RX_BW_M10 >= 1250) && (MODUL_TYPE == OOK))
    #define RXBW 0x01
#elif ((RX_BW_M10 >= 1000) && (MODUL_TYPE == OOK))
    #define RXBW 0x09
#elif ((RX_BW_M10 >= 833) && (MODUL_TYPE == OOK))
    #define RXBW 0x11
#elif ((RX_BW_M10 >= 625) && (MODUL_TYPE == OOK))
    #define RXBW 0x02
#elif ((RX_BW_M10 >= 500) && (MODUL_TYPE == OOK))
    #define RXBW 0x0a
#elif ((RX_BW_M10 >= 417) && (MODUL_TYPE == OOK))
    #define RXBW 0x12
#elif ((RX_BW_M10 >= 313) && (MODUL_TYPE == OOK))
    #define RXBW 0x03
#elif ((RX_BW_M10 >= 250) && (MODUL_TYPE == OOK))
    #define RXBW 0x0b
#elif ((RX_BW_M10 >= 208) && (MODUL_TYPE == OOK))
    #define RXBW 0x13
#elif ((RX_BW_M10 >= 156) && (MODUL_TYPE == OOK))
    #define RXBW 0x04
#elif ((RX_BW_M10 >= 125) && (MODUL_TYPE == OOK))
    #define RXBW 0x0c
#elif ((RX_BW_M10 >= 104) && (MODUL_TYPE == OOK))
    #define RXBW 0x14
#elif ((RX_BW_M10 >= 78) && (MODUL_TYPE == OOK))
    #define RXBW 0x05
#elif ((RX_BW_M10 >= 63) && (MODUL_TYPE == OOK))
    #define RXBW 0x0d
#elif ((RX_BW_M10 >= 52) && (MODUL_TYPE == OOK))
    #define RXBW 0x15
#elif ((RX_BW_M10 >= 39) && (MODUL_TYPE == OOK))
    #define RXBW 0x06
#elif ((RX_BW_M10 >= 31) && (MODUL_TYPE == OOK))
    #define RXBW 0x0e
#elif ((RX_BW_M10 >= 26) && (MODUL_TYPE == OOK))
    #define RXBW 0x16
#elif ((RX_BW_M10 >= 20) && (MODUL_TYPE == OOK))
    #define RXBW 0x07
#elif ((RX_BW_M10 >= 16) && (MODUL_TYPE == OOK))
    #define RXBW 0x0f
#elif ((RX_BW_M10 >= 13) && (MODUL_TYPE == OOK))
    #define RXBW 0x17
#endif

// table for REGAFCBW			0x1a

#define	CUT_OFF_FREQ_AFC_M100	CUT_OFF_FREQ_AFC*100

#if (CUT_OFF_FREQ_AFC_M100 >= 1600)
    #define DCCFREQAFC 0x00
#elif (CUT_OFF_FREQ_AFC_M100 >= 800)
    #define DCCFREQAFC 0x20
#elif (CUT_OFF_FREQ_AFC_M100 >= 400)
    #define DCCFREQAFC 0x40
#elif (CUT_OFF_FREQ_AFC_M100 >= 200)
    #define DCCFREQAFC 0x60
#elif (CUT_OFF_FREQ_AFC_M100 >= 100)
    #define DCCFREQAFC 0x80
#elif (CUT_OFF_FREQ_AFC_M100 >= 50)
    #define DCCFREQAFC 0xa0
#elif (CUT_OFF_FREQ_AFC_M100 >= 25)
    #define DCCFREQAFC 0xc0
#elif (CUT_OFF_FREQ_AFC_M100 >= 13)
    #define DCCFREQAFC 0xe0
#endif

#define	RX_BW_AFC_M10	RX_BW_AFC*10

#if ((RX_BW_AFC_M10 >= 5000) && (MODUL_TYPE == FSK))
    #define RXBWAFC 0x00
#elif ((RX_BW_AFC_M10 >= 4000) && (MODUL_TYPE == FSK))
    #define RXBWAFC 0x08
#elif ((RX_BW_AFC_M10 >= 3333) && (MODUL_TYPE == FSK))
    #define RXBWAFC 0x10
#elif ((RX_BW_AFC_M10 >= 2500) && (MODUL_TYPE == FSK))
    #define RXBWAFC 0x01
#elif ((RX_BW_AFC_M10 >= 2000) && (MODUL_TYPE == FSK))
    #define RXBWAFC 0x09
#elif ((RX_BW_AFC_M10 >= 1667) && (MODUL_TYPE == FSK))
    #define RXBWAFC 0x11
#elif ((RX_BW_AFC_M10 >= 1250) && (MODUL_TYPE == FSK))
    #define RXBWAFC 0x02
#elif ((RX_BW_AFC_M10 >= 1000) && (MODUL_TYPE == FSK))
    #define RXBWAFC 0x0a
#elif ((RX_BW_AFC_M10 >= 833) && (MODUL_TYPE == FSK))
    #define RXBWAFC 0x12
#elif ((RX_BW_AFC_M10 >= 625) && (MODUL_TYPE == FSK))
    #define RXBWAFC 0x03
#elif ((RX_BW_AFC_M10 >= 500) && (MODUL_TYPE == FSK))
    #define RXBWAFC 0x0b
#elif ((RX_BW_AFC_M10 >= 417) && (MODUL_TYPE == FSK))
    #define RXBWAFC 0x13
#elif ((RX_BW_AFC_M10 >= 313) && (MODUL_TYPE == FSK))
    #define RXBWAFC 0x04
#elif ((RX_BW_AFC_M10 >= 250) && (MODUL_TYPE == FSK))
    #define RXBWAFC 0x0c
#elif ((RX_BW_AFC_M10 >= 208) && (MODUL_TYPE == FSK))
    #define RXBWAFC 0x14
#elif ((RX_BW_AFC_M10 >= 156) && (MODUL_TYPE == FSK))
    #define RXBWAFC 0x05
#elif ((RX_BW_AFC_M10 >= 125) && (MODUL_TYPE == FSK))
    #define RXBWAFC 0x0d
#elif ((RX_BW_AFC_M10 >= 104) && (MODUL_TYPE == FSK))
    #define RXBWAFC 0x15
#elif ((RX_BW_AFC_M10 >= 78) && (MODUL_TYPE == FSK))
    #define RXBWAFC 0x06
#elif ((RX_BW_AFC_M10 >= 63) && (MODUL_TYPE == FSK))
    #define RXBWAFC 0x0e
#elif ((RX_BW_AFC_M10 >= 52) && (MODUL_TYPE == FSK))
    #define RXBWAFC 0x16
#elif ((RX_BW_AFC_M10 >= 39) && (MODUL_TYPE == FSK))
    #define RXBWAFC 0x07
#elif ((RX_BW_AFC_M10 >= 31) && (MODUL_TYPE == FSK))
    #define RXBWAFC 0x0f
#elif ((RX_BW_AFC_M10 >= 26) && (MODUL_TYPE == FSK))
    #define RXBWAFC 0x17
#endif

#if ((RX_BW_AFC_M10 >= 2500) && (MODUL_TYPE == OOK))
    #define RXBWAFC 0x00
#elif ((RX_BW_AFC_M10 >= 2000) && (MODUL_TYPE == OOK))
    #define RXBWAFC 0x08
#elif ((RX_BW_AFC_M10 >= 1667) && (MODUL_TYPE == OOK))
    #define RXBWAFC 0x10
#elif ((RX_BW_AFC_M10 >= 1250) && (MODUL_TYPE == OOK))
    #define RXBWAFC 0x01
#elif ((RX_BW_AFC_M10 >= 1000) && (MODUL_TYPE == OOK))
    #define RXBWAFC 0x09
#elif ((RX_BW_AFC_M10 >= 833) && (MODUL_TYPE == OOK))
    #define RXBWAFC 0x11
#elif ((RX_BW_AFC_M10 >= 625) && (MODUL_TYPE == OOK))
    #define RXBWAFC 0x02
#elif ((RX_BW_AFC_M10 >= 500) && (MODUL_TYPE == OOK))
    #define RXBWAFC 0x0a
#elif ((RX_BW_AFC_M10 >= 417) && (MODUL_TYPE == OOK))
    #define RXBWAFC 0x12
#elif ((RX_BW_AFC_M10 >= 313) && (MODUL_TYPE == OOK))
    #define RXBWAFC 0x03
#elif ((RX_BW_AFC_M10 >= 250) && (MODUL_TYPE == OOK))
    #define RXBWAFC 0x0b
#elif ((RX_BW_AFC_M10 >= 208) && (MODUL_TYPE == OOK))
    #define RXBWAFC 0x13
#elif ((RX_BW_AFC_M10 >= 156) && (MODUL_TYPE == OOK))
    #define RXBWAFC 0x04
#elif ((RX_BW_AFC_M10 >= 125) && (MODUL_TYPE == OOK))
    #define RXBWAFC 0x0c
#elif ((RX_BW_AFC_M10 >= 104) && (MODUL_TYPE == OOK))
    #define RXBWAFC 0x14
#elif ((RX_BW_AFC_M10 >= 78) && (MODUL_TYPE == OOK))
    #define RXBWAFC 0x05
#elif ((RX_BW_AFC_M10 >= 63) && (MODUL_TYPE == OOK))
    #define RXBWAFC 0x0d
#elif ((RX_BW_AFC_M10 >= 52) && (MODUL_TYPE == OOK))
    #define RXBWAFC 0x15
#elif ((RX_BW_AFC_M10 >= 39) && (MODUL_TYPE == OOK))
    #define RXBWAFC 0x06
#elif ((RX_BW_AFC_M10 >= 31) && (MODUL_TYPE == OOK))
    #define RXBWAFC 0x0e
#elif ((RX_BW_AFC_M10 >= 26) && (MODUL_TYPE == OOK))
    #define RXBWAFC 0x16
#elif ((RX_BW_AFC_M10 >= 20) && (MODUL_TYPE == OOK))
    #define RXBWAFC 0x07
#elif ((RX_BW_AFC_M10 >= 16) && (MODUL_TYPE == OOK))
    #define RXBWAFC 0x0f
#elif ((RX_BW_AFC_M10 >= 13) && (MODUL_TYPE == OOK))
    #define RXBW 0x17
#endif

// table for OOKTHRESAVERAGE 0x80

#define	OOK_PEAK_THRESH_STEP_M10	OOK_PEAK_THRESH_STEP*10

#if (OOK_PEAK_THRESH_STEP_M10 >= 60)
	#define	OOKPEAKTHRESHSTEP	0x38
#elif (OOK_PEAK_THRESH_STEP_M10 >= 50)
	#define	OOKPEAKTHRESHSTEP	0x30
#elif (OOK_PEAK_THRESH_STEP_M10 >= 40)
	#define	OOKPEAKTHRESHSTEP	0x28
#elif (OOK_PEAK_THRESH_STEP_M10 >= 30)
	#define	OOKPEAKTHRESHSTEP	0x20
#elif (OOK_PEAK_THRESH_STEP_M10 >= 20)
	#define	OOKPEAKTHRESHSTEP	0x18
#elif (OOK_PEAK_THRESH_STEP_M10 >= 15)
	#define	OOKPEAKTHRESHSTEP	0x10
#elif (OOK_PEAK_THRESH_STEP_M10 >= 10)
	#define	OOKPEAKTHRESHSTEP	0x08
#elif (OOK_PEAK_THRESH_STEP_M10 >= 5)
	#define	OOKPEAKTHRESHSTEP	0x00
#endif

#define	OOK_PEAK_THRESH_DEC_M100		OOK_PEAK_THRESH_DEC*100

#if (OOK_PEAK_THRESH_DEC_M100 >= 1600)
	#define	OOKPEAKTHRESHDEC	0x07
#elif (OOK_PEAK_THRESH_DEC_M100 >= 800)
	#define OOKPEAKTHRESHDEC	0x06
#elif (OOK_PEAK_THRESH_DEC_M100 >= 400)
	#define OOKPEAKTHRESHDEC	0x05
#elif (OOK_PEAK_THRESH_DEC_M100 >= 200)
	#define OOKPEAKTHRESHDEC	0x04
#elif (OOK_PEAK_THRESH_DEC_M100 >= 100)
	#define OOKPEAKTHRESHDEC	0x00
#elif (OOK_PEAK_THRESH_DEC_M100 >= 50)
	#define OOKPEAKTHRESHDEC	0x01
#elif (OOK_PEAK_THRESH_DEC_M100 >= 25)
	#define OOKPEAKTHRESHDEC	0x02
#elif (OOK_PEAK_THRESH_DEC_M100 >= 13)
	#define OOKPEAKTHRESHDEC	0x03
#endif

// table for RESTARTRX

#if ( (AUTO_RESTART_RX_DELAY*BITRATE) >= 4096000)
	#define	INTERPACKETRXDELAY	0xb0
#elif ( (AUTO_RESTART_RX_DELAY*BITRATE) >= 2048000)
	#define	INTERPACKETRXDELAY	0xb0
#elif ( (AUTO_RESTART_RX_DELAY*BITRATE) >= 1024000)
	#define	INTERPACKETRXDELAY	0xa0
#elif ( (AUTO_RESTART_RX_DELAY*BITRATE) >= 512000)
	#define	INTERPACKETRXDELAY	0x90
#elif ( (AUTO_RESTART_RX_DELAY*BITRATE) >= 256000)
	#define	INTERPACKETRXDELAY	0x80
#elif ( (AUTO_RESTART_RX_DELAY*BITRATE) >= 128000)
	#define	INTERPACKETRXDELAY	0x70
#elif ( (AUTO_RESTART_RX_DELAY*BITRATE) >= 64000)
	#define	INTERPACKETRXDELAY	0x60
#elif ( (AUTO_RESTART_RX_DELAY*BITRATE) >= 32000)
	#define	INTERPACKETRXDELAY	0x50
#elif ( (AUTO_RESTART_RX_DELAY*BITRATE) >= 16000)
	#define	INTERPACKETRXDELAY	0x40
#elif ( (AUTO_RESTART_RX_DELAY*BITRATE) >= 8000)
	#define	INTERPACKETRXDELAY	0x30
#elif ( (AUTO_RESTART_RX_DELAY*BITRATE) >= 4000)
	#define	INTERPACKETRXDELAY	0x20
#elif ( (AUTO_RESTART_RX_DELAY*BITRATE) >= 2000)
	#define	INTERPACKETRXDELAY	0x10
#elif ( (AUTO_RESTART_RX_DELAY*BITRATE) >= 1000)
	#define	INTERPACKETRXDELAY	0x00
#else
    #define INTERPACKETRXDELAY  0x00
#endif

#endif // RFM69_TABLE_H_INCLUDED
