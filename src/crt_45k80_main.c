
#include    <pic18.h>

#include 		"crt_45k80_main.h"
#include        "cpu18f45k80.h"
#include		"Analog.h"


unsigned    int		msec=0;

bit bVirt_RxGood = 0;
unsigned int Virt_RxGoodTimer = 0;


void    PortInit(void)
{
	TRISA=0;
	TRISB=0;
	TRISC=0;
	TRISD=0;
	TRISE=0;

  	LATA=0xff;	
  	LATB=0xff;	
  	LATC=0xff;	
  	LATD=0xff;	
  	LATE=0xff;	
}

volatile unsigned int Voltage = 0;
/*
// Timer 기능 구현 	 
*/
void main(void)
{
	unsigned char i;	
    
    di();
    Initial();
    PortInit();
    Timer0Init(); 
	InitAD();
    ei();

	msec=0;
	AN_DONE = 1;

    while (1)
	{ 		
        CLRWDT();

		ProcAD(); // AD 처리 
	
		if (bAD_A_IN_mV_Upd)
		{
			bAD_A_IN_mV_Upd = FALSE;
			Voltage = AD_A_IN_mV;
		}


		
    }
}

	

void interrupt isr(void)
{
   
    if( TMR0IF )		
    {    
        TMR0IF = 0 ;
        TMR0L=MSEC_L;
        TMR0H=MSEC_H;    

        msec++;

        if(msec>1000){
            msec=0;
			LED_TX=!LED_TX;
        } 
    }

    if (ADIF)
    {
        ADIF = 0;
        if (bAdConversion == FALSE)
        {
            ADBuf = ADRES;
            bAdConversion = TRUE;
        }
        AN_DONE = 0;
    }	
}




