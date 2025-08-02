/*
 * Parking.c
 *
 *  Created on: Jan 5, 2025
 *      Author: Eltayib
 */
#ifndef Parking
#include "stm32f1xx_hal.h"
#include <stdio.h>
#include <stdbool.h>



#define MAX_SPACES 200

  // Total parking spaces available
extern volatile int available_spaces;
#define GREEN_LED GPIO_PIN_2   // Green LED for entry OP
#define RED_LED   GPIO_PIN_3   // Red LED for exit OP
#define ENTRY GPIO_PIN_0   // Green LED for entry indication
#define EXIT  GPIO_PIN_1   // Red LED for exit indication
#define LED_PORT  GPIOA        // Port for LEDs

int Car_Entry() {
    if ((available_spaces > 0) && (HAL_GPIO_ReadPin(LED_PORT, ENTRY) == 0)) {
        available_spaces--;
        HAL_GPIO_WritePin(LED_PORT, GREEN_LED, GPIO_PIN_SET);
        HAL_Delay(1000);
        HAL_GPIO_WritePin(LED_PORT, GREEN_LED, GPIO_PIN_RESET);
    }
    else{
    	return 0;
    }
}

int Car_Exit() {
    if ((available_spaces < MAX_SPACES) && (HAL_GPIO_ReadPin(LED_PORT, EXIT) == 0)) {
        available_spaces++;
        HAL_GPIO_WritePin(LED_PORT, RED_LED, GPIO_PIN_SET);
        HAL_Delay(1000);
        HAL_GPIO_WritePin(LED_PORT, RED_LED, GPIO_PIN_RESET);
    }
    else{
        	return 0;
        }
}


char* convertNumberToString(int number, char result[5]) {
    // Ensure the number is within 4-digit range
    if (number > 9999) number = 9999;
    if (number < 0) number = 0;

    // Format the number as a 4-digit string with leading zeros
    sprintf(result, "%04d", number);

    // Return the resulting string
    return result;
}


void Display_Number(int number ,int brightness) {
	char result[5];
    convertNumberToString(number, result);
    tm1637_THEDisplayer(result, brightness);
      }

  int Display_FULL(int brightness) {
	  if (available_spaces == 0){
	      tm1637_THEDisplayer("<<<<", brightness);
	      HAL_Delay(500);
	  	  tm1637_THEDisplayer("F<<<", brightness);
	  	  HAL_Delay(500);
	  	  tm1637_THEDisplayer("FU<<", brightness);
	      HAL_Delay(500);
	      tm1637_THEDisplayer("FUL<", brightness);
	      HAL_Delay(500);
	      tm1637_THEDisplayer("FULL", brightness);
	      HAL_Delay(500);
	  }
	  else{
		  return 0;
	  }
      }



  void Display_Startup(int brightness) {
      tm1637_THEDisplayer("G01", brightness);
      HAL_Delay(4000);
  }

 #endif
