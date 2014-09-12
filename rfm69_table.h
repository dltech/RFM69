
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

// table for REGAFCBW			0x1a

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

// table for OOKTHRESAVERAGE 0x80

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

// table for RESTARTRX

#if ( (RESTART_RX_DELAY*BITRATE) >= 4096000)
	#define	INTERPACKETRXDELAY	0xb0
#elif ( (RESTART_RX_DELAY*BITRATE) >= 2048000)
	#define	INTERPACKETRXDELAY	0xb0
#elif ( (RESTART_RX_DELAY*BITRATE) >= 1024000)
	#define	INTERPACKETRXDELAY	0xa0
#elif ( (RESTART_RX_DELAY*BITRATE) >= 512000)
	#define	INTERPACKETRXDELAY	0x90
#elif ( (RESTART_RX_DELAY*BITRATE) >= 256000)
	#define	INTERPACKETRXDELAY	0x80
#elif ( (RESTART_RX_DELAY*BITRATE) >= 128000)
	#define	INTERPACKETRXDELAY	0x70
#elif ( (RESTART_RX_DELAY*BITRATE) >= 64000)
	#define	INTERPACKETRXDELAY	0x60
#elif ( (RESTART_RX_DELAY*BITRATE) >= 32000)
	#define	INTERPACKETRXDELAY	0x50
#elif ( (RESTART_RX_DELAY*BITRATE) >= 16000)
	#define	INTERPACKETRXDELAY	0x40
#elif ( (RESTART_RX_DELAY*BITRATE) >= 8000)
	#define	INTERPACKETRXDELAY	0x30
#elif ( (RESTART_RX_DELAY*BITRATE) >= 4000)
	#define	INTERPACKETRXDELAY	0x20
#elif ( (RESTART_RX_DELAY*BITRATE) >= 2000)
	#define	INTERPACKETRXDELAY	0x10
#elif ( (RESTART_RX_DELAY*BITRATE) >= 1000)
	#define	INTERPACKETRXDELAY	0x00
#endif
