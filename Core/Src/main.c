/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"
#include "fsmc.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "LCD.h"
#include "lvgl.h"
#include "lv_port_indev_template.h"
#include "lv_port_disp_template.h"
#include "lv_demo_widgets.h"
#include "touch.h"
#include "demo.h"
#include <stdio.h>
#include "tcp.h"
#include "mqtt.h"
#include "esp8266.h"

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */
extern Weather_Result WX_Res;
LV_FONT_DECLARE(font70);
LV_FONT_DECLARE(font20);
/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{

  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_FSMC_Init();
  MX_TIM3_Init();
  MX_USART1_Init();
  MX_USART2_UART_Init();
  /* USER CODE BEGIN 2 */
//ESP8266_STA_TCPClient_Test();
  /* USER CODE END 2 */
	ESP8266_STA_MQTTClient_Test();
	lv_init();
	lv_port_disp_init();
	HAL_TIM_Base_Start_IT(&htim3); 
	lv_port_indev_init();
//	lv_obj_t *my_label = lv_label_create(lv_scr_act());
//	lv_obj_set_style_text_font(my_label,&font70,LV_STATE_DEFAULT);
//	char *weather_info = (char *)malloc(strlen(WX_Res.city) + strlen(WX_Res.text) + strlen(WX_Res.temperature) + strlen(WX_Res.date) + 4 + 1);
//	sprintf(weather_info, "%s,%s,%s,%s", WX_Res.city, WX_Res.text,WX_Res.temperature,WX_Res.date);
//	lv_label_set_text(my_label, weather_info);
//	lv_obj_set_width(my_label, 150); //Set smaller width to make the lines wrap
//	lv_obj_set_style_text_align(my_label, LV_TEXT_ALIGN_CENTER, 0);
//	lv_obj_align(my_label, LV_ALIGN_CENTER, 0, -40);
 // ������ǩ
// ������ǩ

 

//    lv_obj_t * label2 = lv_label_create(lv_scr_act());
//    lv_label_set_long_mode(label2, LV_LABEL_LONG_SCROLL_CIRCULAR);     /*Circular scroll*/
//    lv_obj_set_width(label2, 50);
//    lv_label_set_text(label2, "It is a circularly scrolling tex764653333333333333333333336563t. ");
//    lv_obj_align(label2, LV_ALIGN_CENTER, 0, 40);
// 
//lv_obj_t *label = lv_label_create(lv_scr_act());

//// 动态分配内存存储天气信息
//size_t total_length = strlen(WX_Res.city) + strlen(WX_Res.text) + 
//                      strlen(WX_Res.temperature) + strlen(WX_Res.date) + 5;
//char *weather_info = (char *)malloc(total_length);

//if (weather_info == NULL) {
//    // 内存分配失败，使用默认文本
//    lv_label_set_text(label, "Memory allocation failed!");
//    printf("Error: Memory allocation failed for weather_info\n");
//} else {
//	sprintf(weather_info, "城市:%s,天气:%s,温度:%s,时间:%s 无锡太湖学院 物联网2202赵荣胜 小阿巴老祖", 
//            WX_Res.city, WX_Res.text, WX_Res.temperature, WX_Res.date);
//    
//    // 设置标签文本
//    lv_label_set_text(label, weather_info);
//    
//    // 释放内存(LVGL会复制文本内容)
//    free(weather_info);
//    
//    // 打印实际显示的文本
//    printf("Weather Info: %s\n", lv_label_get_text(label));
//    
//    // 刷新文本外部绘制尺寸
//    lv_obj_refresh_ext_draw_size(label);
//    uint16_t text_width = lv_obj_get_width(label);
//    printf("Text Width: %dpx, Label Width: 200px\n", text_width);
//    
//    // 如果文本宽度小于标签宽度，添加填充字符以便实现滚动效果
//    if (text_width < 200) {
//        char *padded_text = (char *)malloc(total_length + 50);
//        sprintf(padded_text, "%s                    ", lv_label_get_text(label));
//        lv_label_set_text(label, padded_text);
//        free(padded_text);
//        printf("Text too short, added padding for scrolling\n");
//    }
//}

//// 设置长文本模式为循环滚动
//lv_label_set_long_mode(label, LV_LABEL_LONG_SCROLL_CIRCULAR);

//// 设置标签宽度和高度
//lv_obj_set_size(label, 200, 30);

//// 设置文本对齐方式
//lv_obj_set_style_text_align(label, LV_TEXT_ALIGN_LEFT, 0);

//// 如果需要自定义字体，可以取消下面这行注释
//lv_obj_set_style_text_font(label, &font70, 0);

//// 设置滚动速度(值越小速度越快)
//lv_obj_set_style_anim_time(label, 8000, 0);  // 8秒滚动一次

//// 将标签居中对齐
//lv_obj_align(label, LV_ALIGN_CENTER, 0, 0);


  while (1)
  {
    /* USER CODE END WHILE */
 
    /* USER CODE BEGIN 3 */
		HAL_Delay(5);
		lv_task_handler();
  }
  /* USER CODE END 3 */
}


/**
  * @brief System Clock Configuration
  * @retval None
  */
 
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 25;
  RCC_OscInitStruct.PLL.PLLN = 336;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 4;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_5) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */
   void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	if(htim->Instance==TIM3)
	{
		lv_tick_inc(1);
	}}

static uint32_t g_fac_us=0; /*us��ʱ������*/ 
void delay_us(uint32_t nus) 
{ 
	uint32_t ticks; 
	uint32_t told, tnow, tent=0; 
	uint32_t reload=SysTick->LOAD; /*LOAD��ֵ */ 
	ticks= nus* g_fac_us; /*��Ҫ�Ľ����� */ 
	told=SysTick->VAL; /*�ս���ʱ�ļ�����ֵ */ 
	while(1) 
	{ 
		tnow=SysTick->VAL; 
		if(tnow!= told) 
		{ 
				if(tnow< told) 
				{ 
				tent+= told-tnow; 
						/*����ע��һ��SYSTICK��һ���ݼ��ļ������Ϳ����� */ 
					} 
				else 
					{ 
				tent+= reload-tnow+ told; 
						} 
			told = tnow; 
				if(tent>= ticks) 
			{ 
					break; /*ʱ�䳬��/����Ҫ�ӳٵ�ʱ�䣬���˳� */ 
			} 
}} }
void load_draw_dialog(void) 
{ 
 lcd_clear(WHITE); /*���� */ 
 lcd_show_string(lcddev.width-24,0,200,16,16, "RST",BLUE);/* ��ʾ�������� */
} 
/** 
*@ brief ���败�������Ժ��� 
*@ param �� 
*@ retval �� 
*/ 
void rtp_test(void) 
{
		while(1) 
		{ 
			tp_dev.scan(0); 
if(tp_dev.sta& TP_PRES_DOWN) /* ������������ */ 
{ 
if(tp_dev.x[0] < lcddev.width && tp_dev.y[0] < lcddev.height) 
{ 
if(tp_dev.x[0] > (lcddev.width -24) && tp_dev.y[0]<16) 
{ 
load_draw_dialog();/* ��� */ 
} 
else 
{ 
tp_draw_big_point(tp_dev.x[0], tp_dev.y[0],RED); /* ���� */ 
} 
} 
} 
else 
{ 
HAL_Delay(10); /*û�а������µ�ʱ�� */ 
} 
} 
}
/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
