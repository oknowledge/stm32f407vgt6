#ifndef __MQTT_H
#define __MQTT_H 			   
#include "main.h"


/*
*���²�����Ҫ�û������޸Ĳ��ܲ����ù�
*/


#define User_ESP8266_SSID     "504"    //wifi��
#define User_ESP8266_PWD      "27402730"      //wifi����

#define User_ESP8266_client_id    "k2719oFu78O.MK54|securemode=2,signmethod=hmacsha256,timestamp=1743738810689|"    //MQTTclientID ���ڱ�־client���  �256�ֽ�
#define User_ESP8266_username     "MK54&k2719oFu78O"						//���ڵ�¼ MQTT ������ �� username, � 64 �ֽ�	
#define User_ESP8266_password			"5377eff0c2f363ed93f59bba8d0e4284414441dcd3ca8ffaa125e5201099b96b"          //���ڵ�¼ MQTT ������ �� password, � 64 �ֽ�
#define User_ESP8266_MQTTServer_IP     "192.168.31.16"     //MQTT���ط�����IP
#define User_ESP8266_MQTTServer_PORT   1883     //�������˿ں�
#define User_ESP8266_MQTTServer_Topic  "topic"    //����MQTT����
 
void ESP8266_STA_MQTTClient_Test(void);
 
#endif
