#ifndef __MQTT_H
#define __MQTT_H 			   
#include "main.h"


/*
*以下参数需要用户自行修改才能测试用过
*/


#define User_ESP8266_SSID     "504"    //wifi名
#define User_ESP8266_PWD      "27402730"      //wifi密码

#define User_ESP8266_client_id    "k2719oFu78O.MK54|securemode=2,signmethod=hmacsha256,timestamp=1743738810689|"    //MQTTclientID 用于标志client身份  最长256字节
#define User_ESP8266_username     "MK54&k2719oFu78O"						//用于登录 MQTT 服务器 的 username, 最长 64 字节	
#define User_ESP8266_password			"5377eff0c2f363ed93f59bba8d0e4284414441dcd3ca8ffaa125e5201099b96b"          //用于登录 MQTT 服务器 的 password, 最长 64 字节
#define User_ESP8266_MQTTServer_IP     "192.168.31.16"     //MQTT本地服务器IP
#define User_ESP8266_MQTTServer_PORT   1883     //服务器端口号
#define User_ESP8266_MQTTServer_Topic  "topic"    //订阅MQTT主题
 
void ESP8266_STA_MQTTClient_Test(void);
 
#endif
