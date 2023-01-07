/**
  ******************************************************************************
  * @file    Templates/Src/main.c 
  * @author  MCD Application Team
  * @brief   Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2016 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/

#include "sys.h"
#include "delay.h"
#include "usart.h"

/** @addtogroup STM32F1xx_HAL_Examples
  * @{
  */

/** @addtogroup Templates
  * @{
  */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/
void Delay(__IO uint32_t nCount);
void Delay(__IO uint32_t nCount)
{
while(nCount--){}
}
/**
  * @brief  Main program
  * @param  None
  * @retval None
  */

int main(void)
{
	GPIO_InitTypeDef GPIO_Initure;
     
    HAL_Init();                    	 			//??'??HAL??    
    Stm32_Clock_Init(RCC_PLL_MUL9);   			//???????,72M

    __HAL_RCC_GPIOB_CLK_ENABLE();           	//????GPIOB???
	  __HAL_RCC_GPIOE_CLK_ENABLE();           	//????GPIOE???
	
    GPIO_Initure.Pin=GPIO_PIN_5; 				//PB5
    GPIO_Initure.Mode=GPIO_MODE_OUTPUT_PP;  	//???????
    GPIO_Initure.Pull=GPIO_PULLUP;          	//????
    GPIO_Initure.Speed=GPIO_SPEED_FREQ_HIGH;    //????
    HAL_GPIO_Init(GPIOB,&GPIO_Initure);

	GPIO_Initure.Pin=GPIO_PIN_5; 				//PE5
	HAL_GPIO_Init(GPIOE,&GPIO_Initure);
	
	while(1)
	{
		HAL_GPIO_WritePin(GPIOB,GPIO_PIN_5,GPIO_PIN_SET);		//PB5??1 
		HAL_GPIO_WritePin(GPIOE,GPIO_PIN_5,GPIO_PIN_SET);		//PE5??1  			
		Delay(0x7FFFFF);
		HAL_GPIO_WritePin(GPIOB,GPIO_PIN_5,GPIO_PIN_RESET);		//PB5??0
		HAL_GPIO_WritePin(GPIOE,GPIO_PIN_5,GPIO_PIN_RESET);		//PE5??0  
		Delay(0x7FFFFF);
Delay(0x7FFFFF);
Delay(0x7FFFFF);
Delay(0x7FFFFF);
	}
}