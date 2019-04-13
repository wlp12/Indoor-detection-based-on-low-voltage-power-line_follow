#ifndef _DATABOX_H
#define _DATABOX_H


#define  Rdata_tip      0x72 //��r�ַ�
#define  Tdata_tip      0x74 //��t�ַ�

#define  Main_Address   0x47 //G
#define  F_Address_0    0x48 //H  ����
#define  F_Address_1    0x49 //I  ����
#define  F_Address_2    0x4a //J  ԡ��
#define  F_Address_3    0x4b //K  ����

#define  command_0      0x67 //g  ���������������ã���ʱ���������ʹӻ��ɼ��Ļ�������
#define  command_1      0x68 //h  ����
#define  command_1s     0x69 //i  �ص�
#define  command_2      0x6a //j  ���յ�
#define  command_2s     0x6b //k  �ؿյ�
#define  command_3      0x6c //l  ������
#define  command_3s     0x6d //m  �ط���
#define  command_4      0x6e //n  �����̻�
#define  command_4s     0x6f //o  �����̻�
#define  command_open   0x70 //p  ����ȫ��
#define  command_close  0x71 //q  ����ȫ��
#define  command_warn   0x73 //s  ���������ɼ�ֵ�������������;���
#define  command_warns  0x75 //u  �رվ���
#define  command_reset  0x76 //v  ����������������ӻ���ʼ��

#define main_part     0  //����
#define fellow_part0  0  //�ӻ�0
#define fellow_part1  0  //�ӻ�1
#define fellow_part2  0  //�ӻ�2
#define fellow_part3  1  //�ӻ�3

void cheak_databox(void);
void send_databox(char a,char b,char c,int d,char *e,int  way);
typedef struct 
 {
	unsigned   address;
  unsigned 	char funtion_part;
	int       data_length;		  
 }DATABOX;



#endif
