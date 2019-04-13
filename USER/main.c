#include "led.h"
#include "delay.h"
#include "key.h"
#include "sys.h"
#include "lcd.h"
#include "usart.h"
#include "adc.h"
#include "lsens.h"
#include "dht11.h"
#include "databox.h"
#include "timer.h"
#include "stdlib.h"
#include "beep.h"

char   string[20];
extern DATABOX databox1,databox3;
extern DATABOX *sptr1,*sptr3;
extern u8 my_result1[100];
void Init(void);

char* change_nc(int m)
{
 int p;
 char *str5;
 char str1[20];
 char hundred,ten,one;
  hundred=(char)(m/100+'0');
	p=(int)(m/100);
  ten=(char)((m-p*100)/10+'0');
  one=(char)(m%10+'0');
  sprintf(str1,"%c%c%c",hundred,ten,one);
	str5=str1;
  return str5;
}

void Smoke_Warn(int m)
{
	switch(m)
	{
	case 1:
		 BEEP=1;
	   delay_ms(40);   
	   send_databox(Tdata_tip,F_Address_0,command_warn,20,string,1);
	   BEEP=0;
	   delay_ms(1000);   
	   break;
	case 2:
		 BEEP=1;
     delay_ms(60);   
	   send_databox(Tdata_tip,F_Address_0,command_warn,20,string,1);
	   BEEP=0;
	   delay_ms(600);   
	   break;
	case 3:
		 BEEP=1;
     delay_ms(80);   
	   send_databox(Tdata_tip,F_Address_0,command_warn,20,string,1);
	   BEEP=0;
	   delay_ms(500);   
	   break;
  }
}
void Init(void)
{
  delay_init();	    	 //延时函数初始化	  
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);	 //设置NVIC中断分组2:2位抢占优先级，2位响应优先级
	uart_init(4800);	 	//串口初始化为115200
	TIM3_Int_Init(999,71);//10Khz的计数频率，计数到500为500ms 
 	LED_Init();			     //LED端口初始化
	LCD_Init();
	Adc2_Init();
	BEEP_Init();
	Lsens_Init(); 			//初始化光敏传感器
	POINT_COLOR=RED; 
  DHT11_Init();	 
}
 int main(void)
 {			 
  u8 temperature;  	    
	u8 humidity;  
  u8 adcx;
	int mode;
	int smoke;	 
	char *t;
	char string0[3]; 
	char string1[3];
	char string2[3];
  Init();
  while(1) 
	 {				 
	  DHT11_Read_Data(&temperature,&humidity);	//读取温湿度值	
		adcx=Lsens_Get_Val();
		LCD_ShowNum(30+210,70,temperature,2,16);	//显示温度	   		   
		LCD_ShowNum(30+180,90,humidity,2,16);		  //显示湿度	 	  
		LCD_ShowxNum(30+120,110,adcx,3,16,0);     //显示ADC的值 
		smoke=(int)(Get_Adc_Average(2,12)/8);
    mode=smoke/200;	
    Smoke_Warn(mode);		 	
		t=change_nc((int)(temperature));
		sprintf(string0,"%s",t);
		t=change_nc((int)(humidity)); 
		sprintf(string1,"%s",t); 
		t=change_nc((int)(adcx)); 
		sprintf(string2,"%s",t);
		t=change_nc(smoke);	
		sprintf(string,"%s%s%s%s",string0,string1,string2,t); 
	  cheak_databox();			
    delay_ms(1000);	
 	} 
}
