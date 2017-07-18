
#ifndef _cpu18f4480_h_
#define _cpu18f4480_h_




#ifndef TRUE
#define TRUE	1
#endif

#ifndef FALSE
#define FALSE	0
#endif


#define	HOST_COMPANY	'A'


unsigned char TX_DATA_CNT = 0;
//#define	TX_DATA_CNT		40     
//#define	TX_DATA_CNT		88     


#define	CPU45K80		1

#define	U_COMPILER		1


#define	MAX_SAVE_BUF_CAN    HOST_DATA_RECOD * MAX_ELEV

#define	TRMT	TRMT1	
#define	OERR	OERR1
#define	TXEN	TXEN1
#define	SPEN	SPEN1
#define	FERR	FERR1
#define	CREN	CREN1

#define     MSEC_H    0xfc
#define     MSEC_L    0x18
















unsigned int LcdDelay = 0;



bit msgCANRx_EleData_Updated = 0;

unsigned char SelInit = 0;
char next = 0;

unsigned    char    LocalNumber=0;


#define MAX_PACKET 30
char com1_buf[MAX_PACKET];





unsigned    char    CanKeyValue[8];
unsigned    char  CarKey[4]={0,0,0,0}; 

unsigned    char  newKeyScan[4] = {0, 0, 0, 0};
unsigned    char  oldKeyScan[4] = {0, 0, 0, 0};
unsigned    char  KeyScantimer[4] = {0, 0, 0, 0};

unsigned    char  EqualFlr;
unsigned    char  HighFlr;
unsigned    char  LowFlr;


unsigned    char  MyBaseFlr = 0;

bit bTouchPress;
bit bEndTestLCDMode;

extern void SetCom1TxEnable(void);
extern bit Draw_ButtonOff_3F(void);
extern bit Draw_ButtonOff_2F(void);
extern bit Draw_ButtonOff_1F(void);
extern void  ChkKeyButtonPush(void);
extern void  SetKey(unsigned char, unsigned char, unsigned char*);
extern int IsKeyLoaded(unsigned char);
extern unsigned char  ChkCarKeyLoad(unsigned char);
extern unsigned char SetHighFloor(unsigned char);
extern unsigned char SetLowFloor(unsigned char);

extern  void  Initial(void);
extern  void  Timer0Init(void);



#endif


