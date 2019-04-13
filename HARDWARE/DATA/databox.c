#include "databox.h"
#include "usart.h"
#include "stdlib.h"
#include "lcd.h"
#include "delay.h"
#include "led.h"
#include "beep.h"


int command_flag1[4][6];
int command_flag3[4][6];
int acv_flag3,acv_flag1;
extern int num1;
extern DATABOX databox1,databox3;
extern DATABOX *sptr1,*sptr3;
extern void Init(void);

#if main_part  
int saloon[4],kitchen[4],shower[4],bed[4];
void cheak_databox(void)
{
 int i;
 if(acv_flag1==2)
	 {
		 if(sptr1->address==Main_Address) 
	      {
        if(sptr1->funtion_part==command_0)       command_flag1[0][0]=1;
    	  else if(sptr1->funtion_part==command_1)  command_flag1[0][1]=1;
    	  else if(sptr1->funtion_part==command_2)  command_flag1[0][2]=1;
        }
	   else if(sptr1->address==F_Address_0) 
	      {
        if(sptr1->funtion_part==command_0)       
			  {
			    for(i=0;i<4;i++)
			    {
				   saloon[i]= char_num(my_result1[3*i],my_result1[3*i+1],my_result1[3*i+2]);				 
				  }		 
			   }
    	 else if(sptr1->funtion_part== command_warn)   {     beep_warn();  }
        }
     else if(sptr1->address==F_Address_1) 
	      {
        if(sptr1->funtion_part==command_0)       
			  {
			    for(i=0;i<4;i++)
			    {
				   kitchen[i]= char_num(my_result1[3*i],my_result1[3*i+1],my_result1[3*i+2]);				 
				  }		 
			   }
    	 else if(sptr1->funtion_part== command_warn)   {     beep_warn();  }
        }
     else if(sptr1->address==F_Address_2) 
	       {
         if(sptr1->funtion_part==command_0)       
			   {
			    for(i=0;i<4;i++)
			    {
				   shower[i]= char_num(my_result1[3*i],my_result1[3*i+1],my_result1[3*i+2]);				 
				  }		 
			   }
    	 else if(sptr1->funtion_part== command_warn)   {     beep_warn();  }
        }
    else if(sptr1->address==F_Address_3) 
	      {
        if(sptr1->funtion_part==command_0)       
			   {
			    for(i=0;i<4;i++)
			    {
				   bed[i]= char_num(my_result1[3*i],my_result1[3*i+1],my_result1[3*i+2]);				 
				  }		 
			   }
    	 else if(sptr1->funtion_part== command_warn)   {     beep_warn();  }
         }
		 }
if(acv_flag3==2)
	{
     if(sptr3->address==F_Address_0) 
      {
       if(sptr3->funtion_part==command_0)       command_flag3[0][0]=1;
    	 else if(sptr3->funtion_part==command_1)  command_flag3[0][1]=1;
    	 else if(sptr3->funtion_part==command_2)  command_flag3[0][2]=1;
      }
     else if(sptr3->address==F_Address_1) 
      {
       if(sptr3->funtion_part==command_0)       command_flag3[1][0]=1;
    	 else if(sptr3->funtion_part==command_1)  command_flag3[1][1]=1; 
    	 else if(sptr3->funtion_part==command_2)  command_flag3[1][2]=1;
      }
     else if(sptr3->address==F_Address_2) 
      {
       if(sptr3->funtion_part==command_0)       command_flag3[2][0]=1;
    	 else if(sptr3->funtion_part==command_1)  command_flag3[2][1]=1; 
    	 else if(sptr3->funtion_part==command_2)  command_flag3[2][2]=1;
      }	
     else if(sptr3->address==F_Address_3) 
      {
       if(sptr3->funtion_part==command_0)       command_flag3[3][0]=1;
    	 else if(sptr3->funtion_part==command_1)  command_flag3[3][1]=1; 
    	 else if(sptr3->funtion_part==command_2)  command_flag3[3][2]=1;
      }			
    }

}
#endif

#if fellow_part0   
void cheak_databox(void)
{
	while(num1-->0)
	{
	 if(sptr1->address==F_Address_0) 
	  {
	   if(sptr1->funtion_part==command_1)             {  LED = 1;	 }
		 else if(sptr1->funtion_part==command_1s)       {  LED = 0;  }
		 else if(sptr1->funtion_part==command_2)        {  AIR = 1;	 }
		 else if(sptr1->funtion_part==command_2s)       {  AIR = 0;  }
		 else if(sptr1->funtion_part==command_3)        {  FAN = 1;  }
		 else if(sptr1->funtion_part==command_3s)       {  FAN = 0;  }
		 else if(sptr1->funtion_part==command_4)        {  Cooker = 1;  }
		 else if(sptr1->funtion_part==command_4s)       {  Cooker = 0;  }
		 else if(sptr1->funtion_part==command_warns)    {  BEEP = 0; }
		 else if(sptr1->funtion_part==command_open)     {  LED = 1;  AIR = 1 ; FAN = 1; Cooker = 1; }
		 else if(sptr1->funtion_part==command_close)    {  LED = 0;  AIR = 0 ; FAN = 0; Cooker = 0; }
		 else if(sptr1->funtion_part==command_reset)    {  Init();	delay_ms(5); }
	  }	
	 if(sptr3->address==F_Address_0) 
	  {
	   if(sptr3->funtion_part==command_0)       command_flag3[0][0]=1;
		 else if(sptr3->funtion_part==command_1)  command_flag3[0][1]=1;
		 else if(sptr3->funtion_part==command_2)  command_flag3[0][2]=1;
	  } 
	 else 
	 return;
	} 
}
#endif

#if fellow_part1   
void cheak_databox(void)
{
while(num1-->0)
	{
	if(sptr1->address==F_Address_1) 
	  {
	   if(sptr1->funtion_part==command_1)             {  LED = 1;	 }
		 else if(sptr1->funtion_part==command_1s)       {  LED = 0;  }
		 else if(sptr1->funtion_part==command_2)        {  AIR = 1;	 }
		 else if(sptr1->funtion_part==command_2s)       {  AIR = 0;  }
		 else if(sptr1->funtion_part==command_3)        {  FAN = 1;  }
		 else if(sptr1->funtion_part==command_3s)       {  FAN = 0;  }
		 else if(sptr1->funtion_part==command_4)        {  Cooker = 1;  }
		 else if(sptr1->funtion_part==command_4s)       {  Cooker = 0;  }
		 else if(sptr1->funtion_part==command_warn)     {  BEEP = 1; delay_ms(500); BEEP = 0;delay_ms(500);BEEP = 1; delay_ms(500); BEEP = 0;delay_ms(500); }
		 else if(sptr1->funtion_part==command_warns)    {  BEEP = 0; }
		 else if(sptr1->funtion_part==command_open)     {  LED = 1;  AIR = 1 ; FAN = 1; Cooker = 1; }
		 else if(sptr1->funtion_part==command_close)    {  LED = 0;  AIR = 0 ; FAN = 0; Cooker = 0; }
		 else if(sptr1->funtion_part==command_reset)    {  Init();	delay_ms(5); }
	  }	
	 if(sptr3->address==F_Address_1) 
	  {
	   if(sptr3->funtion_part==command_0)       command_flag3[0][0]=1;
		 else if(sptr3->funtion_part==command_1)  command_flag3[0][1]=1;
		 else if(sptr3->funtion_part==command_2)  command_flag3[0][2]=1;
	  } 
	 else 
	 return;
	} 
	}
#endif

#if fellow_part2   
void cheak_databox(void)
{
while(num1-->0)
	{
	 while(num1-->0)
	{
	 if(sptr1->address==F_Address_2) 
	  {
	   if(sptr1->funtion_part==command_1)             {  LED = 1;	 }
		 else if(sptr1->funtion_part==command_1s)       {  LED = 0;  }
		 else if(sptr1->funtion_part==command_2)        {  AIR = 1;	 }
		 else if(sptr1->funtion_part==command_2s)       {  AIR = 0;  }
		 else if(sptr1->funtion_part==command_3)        {  FAN = 1;  }
		 else if(sptr1->funtion_part==command_3s)       {  FAN = 0;  }
		 else if(sptr1->funtion_part==command_4)        {  Cooker = 1;  }
		 else if(sptr1->funtion_part==command_4s)       {  Cooker = 0;  }
     else if(sptr1->funtion_part==command_warns)    {  BEEP = 0; }
		 else if(sptr1->funtion_part==command_open)     {  LED = 1;  AIR = 1 ; FAN = 1; Cooker = 1; }
		 else if(sptr1->funtion_part==command_close)    {  LED = 0;  AIR = 0 ; FAN = 0; Cooker = 0; }
		 else if(sptr1->funtion_part==command_reset)    {  Init();	delay_ms(5); }
	  }	
	 if(sptr3->address==F_Address_2) 
	  {
	   if(sptr3->funtion_part==command_0)       command_flag3[0][0]=1;
		 else if(sptr3->funtion_part==command_1)  command_flag3[0][1]=1;
		 else if(sptr3->funtion_part==command_2)  command_flag3[0][2]=1;
	  } 
	 else 
	 return;
	} 
	}
}
#endif

#if fellow_part3   
void cheak_databox(void)
{
while(num1-->0)
	{
	 if(sptr1->address==F_Address_3) 
	  {
	   if(sptr1->funtion_part==command_1)             {  LED = 1;	 }
		 else if(sptr1->funtion_part==command_1s)       {  LED = 0;  }
		 else if(sptr1->funtion_part==command_2)        {  AIR = 1;	 }
		 else if(sptr1->funtion_part==command_2s)       {  AIR = 0;  }
		 else if(sptr1->funtion_part==command_3)        {  FAN = 1;  }
		 else if(sptr1->funtion_part==command_3s)       {  FAN = 0;  }
		 else if(sptr1->funtion_part==command_4)        {  Cooker = 1;  }
		 else if(sptr1->funtion_part==command_4s)       {  Cooker = 0;  }
		 else if(sptr1->funtion_part==command_warns)    {  BEEP = 0; }
		 else if(sptr1->funtion_part==command_open)     {  LED = 1;  AIR = 1 ; FAN = 1; Cooker = 1; }
		 else if(sptr1->funtion_part==command_close)    {  LED = 0;  AIR = 0 ; FAN = 0; Cooker = 0; }
		 else if(sptr1->funtion_part==command_reset)    {  Init();	delay_ms(5); }
	  }	
	 if(sptr3->address==F_Address_3) 
	  {
	   if(sptr3->funtion_part==command_0)       command_flag3[0][0]=1;
		 else if(sptr3->funtion_part==command_1)  command_flag3[0][1]=1;
		 else if(sptr3->funtion_part==command_2)  command_flag3[0][2]=1;
	  } 
	 else 
	 return;
	} 
}
#endif

//abcdew�ֱ�Ϊ���ݰ����Ⱦ����֣�t��r����b�ǵ�ַ�룬c�ǹ����룬d�����ݳ��ȣ�e����Ч���ݶΣ�way�����Ǵ���1��3
void send_databox(char a,char b,char c,int d,char *e,int way)
{
	char str1;	
	char str2[100];
	str1=(char)(d +'0');
	sprintf(str2,"%c%c%c%c%s\r\n",a,b,c,str1,e);
  if(way==1)       { printf("%s",str2); } 
//  else if(way==3)  { u3_printf("%s",str2);} 
	else return;
}






