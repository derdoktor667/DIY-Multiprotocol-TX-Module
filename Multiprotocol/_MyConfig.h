#pragma once

/*
This file is meant to keep your settings after an upgrade of the multi source.
If you know parameters you want for sure to be enabled or disabled in future
then just force their values here.
To enable  a setting use #undef <setting name>
To disable a setting use #undef  <setting name>
*/

// For example you can also define multiple module configurations, uncomment the one you want to compile for:
#define DIYModule
//#undef Module_2
//#undef Module_2
//#undef Module_4

//Example on how to force the "Flash from TX" feature for all modules
// #undef CHECK_FOR_BOOTLOADER

//Example on how to force the same ID for all modules: be carefull this is really if you want to be able to use one or another radio but not both!
//#undef FORCE_GLOBAL_ID	0x12345678

#if defined DIYModule

// ...setup the "european" default
#define AETR

// ...trigger rebind on channel 16
#define ENABLE_BIND_CH
#define BIND_CH	16
#define WAIT_FOR_BIND

// ...the Chipsets
#define A7105_INSTALLED
#undef  CYRF6936_INSTALLED
#undef  CC2500_INSTALLED
#define NRF24L01_INSTALLED

// ...power
// #define NRF24L01_ENABLE_LOW_POWER

// #define TELEMETRY

// #define INVERT_TELEMETRY

// #define MULTI_TELEMETRY

// #define AFHDS2A_FW_TELEMETRY

#define ENABLE_SERIAL

#define ENABLE_PPM

#define TX_ER9X

#define MIN_PPM_CHANNELS 4

#define MAX_PPM_CHANNELS 16

//The protocols below need an A7105 to be installed
#undef	FLYSKY_A7105_INO
#undef	HUBSAN_A7105_INO
#define	AFHDS2A_A7105_INO

//The protocols below need a CYRF6936 to be installed
#undef	DEVO_CYRF6936_INO
#undef	DSM_CYRF6936_INO
#undef	J6PRO_CYRF6936_INO
#undef	WK2x01_CYRF6936_INO

//The protocols below need a CC2500 to be installed
#undef	FRSKYV_CC2500_INO
#undef	FRSKYD_CC2500_INO
#undef	FRSKYX_CC2500_INO
#undef	SFHSS_CC2500_INO
#undef	CORONA_CC2500_INO

//The protocols below need a NRF24L01 to be installed
#undef	BAYANG_NRF24L01_INO
#undef	CG023_NRF24L01_INO
#define	CX10_NRF24L01_INO		// Include Q2X2 protocol
#undef	ESKY_NRF24L01_INO
#undef	HISKY_NRF24L01_INO
#undef	KN_NRF24L01_INO
#undef	SLT_NRF24L01_INO
#undef	SYMAX_NRF24L01_INO
#undef	V2X2_NRF24L01_INO
#undef	YD717_NRF24L01_INO
#undef	MT99XX_NRF24L01_INO
#undef	MJXQ_NRF24L01_INO
#undef	SHENQI_NRF24L01_INO
#undef	FY326_NRF24L01_INO
#undef	FQ777_NRF24L01_INO
#undef	ASSAN_NRF24L01_INO
#undef	HONTAI_NRF24L01_INO
#undef	Q303_NRF24L01_INO
#undef	GW008_NRF24L01_INO
#undef	DM002_NRF24L01_INO
#define	CABELL_NRF24L01_INO
#undef	ESKY150_NRF24L01_INO
#undef	H8_3D_NRF24L01_INO
#undef	CFLIE_NRF24L01_INO

// ....some fine tuning the AFHDS2A Protocol
// #define FORCE_AFHDS2A_TUNING	45

#define FAILSAFE_ENABLE
#define FAILSAFE_THROTTLE_LOW -125

// ...the protocol switcher
#define NBR_BANKS 1

const PPM_Parameters PPM_prot[14 * NBR_BANKS] = {

#if NBR_BANKS > 0
	//******************************       BANK 1       ******************************
	//	Switch	Protocol 		Sub protocol	RX_Num	Power		Auto Bind		Option
	/*	1	*/{ PROTO_CX10,		CX10_BLUE	,	1	,	P_LOW	,	AUTOBIND	,	0 },
	/*	2	*/{ PROTO_AFHDS2A,	PPM_SBUS	,	2	,	P_HIGH	,	NO_AUTOBIND	,	0 },
	/*	3	*/{ PROTO_AFHDS2A,	PPM_SBUS	,	3	,	P_HIGH	,	NO_AUTOBIND	,	0 },
	/*	4	*/{ PROTO_CABELL,		CABELL_V3	,	4	,	P_HIGH	,	NO_AUTOBIND	,	38 },
	/*	5	*/{ PROTO_CX10,		CX10_BLUE	,	5	,	P_HIGH	,	NO_AUTOBIND	,	0 },
	/*	6	*/{ PROTO_CX10,		CX10_BLUE	,	6	,	P_HIGH	,	NO_AUTOBIND	,	0 },
	/*	7	*/{ PROTO_CX10,		CX10_BLUE	,	7	,	P_HIGH	,	NO_AUTOBIND	,	0 },
	/*	8	*/{ PROTO_CX10,		CX10_BLUE	,	8	,	P_HIGH	,	NO_AUTOBIND	,	0 },
	/*	9	*/{ PROTO_CX10,		CX10_BLUE	,	9	,	P_HIGH	,	NO_AUTOBIND	,	0 },
	/*	10	*/{ PROTO_CX10,		CX10_BLUE	,	10	,	P_HIGH	,	NO_AUTOBIND	,	0 },
	/*	11	*/{ PROTO_CX10,		CX10_BLUE	,	11	,	P_HIGH	,	NO_AUTOBIND	,	0 },
	/*	12	*/{ PROTO_CX10,		CX10_BLUE	,	12	,	P_HIGH	,	NO_AUTOBIND	,	0 },
	/*	13	*/{ PROTO_CX10,		CX10_BLUE	,	13	,	P_HIGH	,	NO_AUTOBIND	,	0 },
	/*	14	*/{ PROTO_CX10,		CX10_BLUE	,	14	,	P_HIGH	,	NO_AUTOBIND	,	0 },
#endif

	//#if NBR_BANKS > 1
	////******************************       BANK 2       ******************************
	////	Switch	Protocol 		Sub protocol	RX_Num	Power		Auto Bind		Option
	///*	1	*/	{PROTO_DSM	,	DSM2_11		,	0	,	P_HIGH	,	NO_AUTOBIND	,	6		},	// option=number of channels
	///*	2	*/	{PROTO_DSM	,	DSM2_22		,	0	,	P_HIGH	,	NO_AUTOBIND	,	6		},	// option=number of channels
	///*	3	*/	{PROTO_DSM	,	DSMX_11		,	0	,	P_HIGH	,	NO_AUTOBIND	,	6		},	// option=number of channels
	///*	4	*/	{PROTO_DSM	,	DSMX_22		,	0	,	P_HIGH	,	NO_AUTOBIND	,	6		},	// option=number of channels
	///*	5	*/	{PROTO_DSM	,	DSM2_11		,	0	,	P_HIGH	,	NO_AUTOBIND	,	8		},	// option=number of channels
	///*	6	*/	{PROTO_DSM	,	DSM2_22		,	0	,	P_HIGH	,	NO_AUTOBIND	,	8		},	// option=number of channels
	///*	7	*/	{PROTO_DSM	,	DSMX_11		,	0	,	P_HIGH	,	NO_AUTOBIND	,	8		},	// option=number of channels
	///*	8	*/	{PROTO_DSM	,	DSMX_22		,	0	,	P_HIGH	,	NO_AUTOBIND	,	8		},	// option=number of channels
	///*	9	*/	{PROTO_SLT	,	0			,	0	,	P_HIGH	,	NO_AUTOBIND	,	0		},
	///*	10	*/	{PROTO_HUBSAN,	H107		,	0	,	P_HIGH	,	NO_AUTOBIND	,	0		},
	///*	11	*/	{PROTO_HUBSAN,	H301		,	0	,	P_HIGH	,	NO_AUTOBIND	,	0		},
	///*	12	*/	{PROTO_HUBSAN,	H501		,	0	,	P_HIGH	,	NO_AUTOBIND	,	0		},
	///*	13	*/	{PROTO_HISKY,	Hisky		,	0	,	P_HIGH	,	NO_AUTOBIND	,	0		},
	///*	14	*/	{PROTO_V2X2	,	0			,	0	,	P_HIGH	,	NO_AUTOBIND	,	0		},
	//#

	//#if NBR_BANKS > 2
	////******************************       BANK 3       ******************************
	////	Switch	Protocol 		Sub protocol	RX_Num	Power		Auto Bind		Option
	///*	1	*/	{PROTO_ESKY	,	0			,	0	,	P_HIGH	,	NO_AUTOBIND	,	0		},
	///*	2	*/	{PROTO_ESKY150,	0			,	0	,	P_HIGH	,	NO_AUTOBIND	,	0		},
	///*	3	*/	{PROTO_ASSAN,	0			,	0	,	P_HIGH	,	NO_AUTOBIND	,	0		},
	///*	4	*/	{PROTO_CORONA,	COR_V2		,	0	,	P_HIGH	,	NO_AUTOBIND	,	0		},
	///*	5	*/	{PROTO_SYMAX,	SYMAX		,	0	,	P_HIGH	,	NO_AUTOBIND	,	0		},
	///*	6	*/	{PROTO_KN	,	WLTOYS		,	0	,	P_HIGH	,	NO_AUTOBIND	,	0		},
	///*	7	*/	{PROTO_BAYANG,	BAYANG		,	0	,	P_HIGH	,	NO_AUTOBIND	,	0		},
	///*	8	*/	{PROTO_BAYANG,	H8S3D		,	0	,	P_HIGH	,	NO_AUTOBIND	,	0		},
	///*	9	*/	{PROTO_BAYANG,	X16_AH		,	0	,	P_HIGH	,	NO_AUTOBIND	,	0		},
	///*	10	*/	{PROTO_BAYANG,	IRDRONE		,	0	,	P_HIGH	,	NO_AUTOBIND	,	0		},
	///*	11	*/	{PROTO_H8_3D,	H8_3D		,	0	,	P_HIGH	,	NO_AUTOBIND	,	0		},
	///*	12	*/	{PROTO_H8_3D,	H20H		,	0	,	P_HIGH	,	NO_AUTOBIND	,	0		},
	///*	13	*/	{PROTO_H8_3D,	H20MINI		,	0	,	P_HIGH	,	NO_AUTOBIND	,	0		},
	///*	14	*/	{PROTO_H8_3D,	H30MINI		,	0	,	P_HIGH	,	NO_AUTOBIND	,	0		},
	//#endif

	//#if NBR_BANKS > 3
	////******************************       BANK 4       ******************************
	////	Switch	Protocol 		Sub protocol	RX_Num	Power		Auto Bind		Option
	///*	1	*/	{PROTO_MJXQ	,	WLH08		,	0	,	P_HIGH	,	NO_AUTOBIND	,	0		},
	///*	2	*/	{PROTO_MJXQ	,	X600		,	0	,	P_HIGH	,	NO_AUTOBIND	,	0		},
	///*	3	*/	{PROTO_MJXQ	,	X800		,	0	,	P_HIGH	,	NO_AUTOBIND	,	0		},
	///*	4	*/	{PROTO_MJXQ	,	H26D		,	0	,	P_HIGH	,	NO_AUTOBIND	,	0		},
	///*	5	*/	{PROTO_MJXQ	,	E010		,	0	,	P_HIGH	,	NO_AUTOBIND	,	0		},
	///*	6	*/	{PROTO_MJXQ	,	H26WH		,	0	,	P_HIGH	,	NO_AUTOBIND	,	0		},
	///*	7	*/	{PROTO_HONTAI,	HONTAI		,	0	,	P_HIGH	,	NO_AUTOBIND	,	0		},
	///*	8	*/	{PROTO_HONTAI,	JJRCX1		,	0	,	P_HIGH	,	NO_AUTOBIND	,	0		},
	///*	9	*/	{PROTO_HONTAI,	X5C1		,	0	,	P_HIGH	,	NO_AUTOBIND	,	0		},
	///*	10	*/	{PROTO_HONTAI,	FQ777_951	,	0	,	P_HIGH	,	NO_AUTOBIND	,	0		},
	///*	11	*/	{PROTO_Q303	,	Q303		,	0	,	P_HIGH	,	NO_AUTOBIND	,	0		},
	///*	12	*/	{PROTO_Q303	,	CX35		,	0	,	P_HIGH	,	NO_AUTOBIND	,	0		},
	///*	13	*/	{PROTO_Q303	,	CX10D		,	0	,	P_HIGH	,	NO_AUTOBIND	,	0		},
	///*	14	*/	{PROTO_Q303	,	CX10WD		,	0	,	P_HIGH	,	NO_AUTOBIND	,	0		},
	//#endif

	//#if NBR_BANKS > 4
	////******************************       BANK 5       ******************************
	////	Switch	Protocol 		Sub protocol	RX_Num	Power		Auto Bind		Option
	///*	1	*/	{PROTO_CX10	,	CX10_GREEN	,	0	,	P_HIGH	,	NO_AUTOBIND	,	0		},
	///*	2	*/	{PROTO_CX10	,	CX10_BLUE	,	0	,	P_HIGH	,	NO_AUTOBIND	,	0		},
	///*	3	*/	{PROTO_CX10	,	DM007		,	0	,	P_HIGH	,	NO_AUTOBIND	,	0		},
	///*	4	*/	{PROTO_CX10	,	JC3015_1	,	0	,	P_HIGH	,	NO_AUTOBIND	,	0		},
	///*	5	*/	{PROTO_CX10	,	JC3015_2	,	0	,	P_HIGH	,	NO_AUTOBIND	,	0		},
	///*	6	*/	{PROTO_CX10	,	MK33041		,	0	,	P_HIGH	,	NO_AUTOBIND	,	0		},
	///*	7	*/	{PROTO_Q2X2	,	Q222		,	0	,	P_HIGH	,	NO_AUTOBIND	,	0		},
	///*	8	*/	{PROTO_Q2X2	,	Q242		,	0	,	P_HIGH	,	NO_AUTOBIND	,	0		},
	///*	9	*/	{PROTO_Q2X2	,	Q282		,	0	,	P_HIGH	,	NO_AUTOBIND	,	0		},
	///*	10	*/	{PROTO_CG023,	CG023		,	0	,	P_HIGH	,	NO_AUTOBIND	,	0		},
	///*	11	*/	{PROTO_CG023,	YD829		,	0	,	P_HIGH	,	NO_AUTOBIND	,	0		},
	///*	12	*/	{PROTO_FQ777,	0			,	0	,	P_HIGH	,	NO_AUTOBIND	,	0		},
	///*	13	*/	{PROTO_YD717,	YD717		,	0	,	P_HIGH	,	NO_AUTOBIND	,	0		},
	///*	14	*/	{PROTO_MT99XX,	MT99		,	0	,	P_HIGH	,	NO_AUTOBIND	,	0		},
	//#endif

};


#elif defined Module_2
//Example of a module which doesn't need the telemetry signal to be inverted
#undef INVERT_TELEMETRY

#elif defined Module_3
//Example of a module which will be used with OpenTX
#undef MULTI_STATUS
#undef MULTI_TELEMETRY

#elif defined Module_4
//Example of a module which will be PPM only
#undef ENABLE_SERIAL

#endif
