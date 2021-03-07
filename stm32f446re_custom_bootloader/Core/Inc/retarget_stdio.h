/*
 * retarget_stdio.h
 *
 *  Created on: Mar 6, 2021
 *      Author: Raj.S
 */

#ifndef INC_RETARGET_STDIO_H_
#define INC_RETARGET_STDIO_H_
#include "stm32f4xx_hal.h"
#include <stdio.h>
#include <errno.h>
#include <sys/stat.h>


UART_HandleTypeDef gHuart;

void RetargetInit(UART_HandleTypeDef *hUART);

#endif /* INC_RETARGET_STDIO_H_ */
