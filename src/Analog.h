
#ifndef		_ANALOG_H_
#define		_ANALOG_H_


typedef	unsigned char	UCHAR;
typedef unsigned int	UINT;
typedef unsigned long 	ULONG;

#ifndef	TRUE
#define	TRUE	1
#endif
#ifndef FALSE
#define	FALSE	0
#endif

#define AN_DONE	DONE

bit	bAn0_Updated = 0;
bit	bAn1_Updated = 0;
bit	bAn2_Updated = 0;
bit	bAn3_Updated = 0;
bit	bAn4_Updated = 0;
bit	bAn5_Updated = 0;
bit	bAn6_Updated = 0;
bit	bAn7_Updated = 0;

bit	bAdConversion = 0;
bit bAdCalcEnable = 0;
unsigned char AdCalcWaitCnt = 0;


unsigned	long    SumAD	= 0;
unsigned 	long    InPutAD = 0;
unsigned 	int	    ADBuf 	= 0;
unsigned	int	    SumCnt	= 0;
unsigned	int	    nSumCnt	= 0;
unsigned    int   	AdChSel	= 0;
unsigned    int   	BefAdChSel	= 0;

#define	nAD_MAX_CHANEL	7
unsigned    int     AdValue[nAD_MAX_CHANEL]; // 채널별 Ad 값 저장 버퍼 

// 5000이면 5V이다.
#define ADCH_MAX	2
unsigned int arInPut_mV[ADCH_MAX] = {0,}; // 각 채널에서 읽어드린 AD 값 
UCHAR arIs_AdUpd[ADCH_MAX] = {0,};

bit bUdtAd = 0;
unsigned int AD_A_IN_mV = 0;
unsigned int AD_V_IN_mV = 0;
bit bAD_A_IN_mV_Upd = FALSE;



bit	IsUdtAd(UINT* arInPut_mV, UCHAR* arIs_AdUpd, UCHAR AdChSel);
void ProcAD(void);
void	InitAD(void);
void GetMyAD(void);
UCHAR ChangeAdChSel(UCHAR AdSel, UCHAR ch);



#endif
