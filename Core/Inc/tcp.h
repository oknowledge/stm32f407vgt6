#ifndef __TCP_H
#define __TCP_H 			   
#include "main.h"


/*
*���²�����Ҫ�û������޸Ĳ��ܲ����ù�
*/

#define User_ESP8266_SSID     "504"          //wifi��
#define User_ESP8266_PWD      "27402730"      //wifi����

#define User_ESP8266_TCPServer_IP     "api.seniverse.com"     //������IP
#define User_ESP8266_TCPServer_PORT   "80"      //�������˿ں�


extern volatile uint8_t TcpClosedFlag;  //����״̬��־
uint8_t ESP8266_ReqRes_DataParsing(char *reqRes, char *keywords, char *result);

typedef struct  //����֡�ṹ��
{
    char city[10];
    char text[10];
    char temperature[5];
    char date[10];
}Weather_Result;
void ESP8266_STA_TCPClient_Test(void);

#endif
