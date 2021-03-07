/*
 * retarget_stdio.c
 *
 *  Created on: 06-Mar-2021
 *      Author: Raj.S
 */

#include "retarget_stdio.h"

#define STDIN_FILENO 0
#define STDOUT_FILENO 1
#define STDERR_FILENO 2

void RetargetInit(UART_HandleTypeDef *hUART)
{
	gHuart.Instance = hUART->Instance;
	gHuart.Init.BaudRate = 115200;
	gHuart.Init.HwFlowCtl = UART_HWCONTROL_NONE;
	gHuart.Init.Mode = UART_MODE_TX_RX;
	gHuart.Init.Parity = UART_PARITY_NONE;
	gHuart.Init.StopBits = UART_STOPBITS_1;
	gHuart.Init.WordLength = UART_WORDLENGTH_8B;
	HAL_UART_Init(&gHuart);

	/* Disable I/O buffering for STDOUT stream, so that
	 * chars are sent out as soon as they are printed. */
	setvbuf(stdout, NULL, _IONBF, 0);
}


/*void HAL_UART_MspInit(UART_HandleTypeDef *huart)
{
	__HAL_RCC_USART2_CLK_ENABLE();
	__HAL_RCC_GPIOA_CLK_ENABLE();

	GPIO_InitTypeDef GPIO_UART2;

	GPIO_UART2.Alternate = GPIO_AF7_USART2;
	GPIO_UART2.Mode = GPIO_MODE_AF_PP;
	GPIO_UART2.Pin = GPIO_PIN_2;		//USART2 Tx
	GPIO_UART2.Pull = GPIO_PULLUP;
	GPIO_UART2.Speed = GPIO_SPEED_FAST;
	HAL_GPIO_Init(GPIOA, &GPIO_UART2);

	GPIO_UART2.Pin = GPIO_PIN_3;		//USART2 Rx
	HAL_GPIO_Init(GPIOA, &GPIO_UART2);

	HAL_NVIC_EnableIRQ(USART2_IRQn);
	HAL_NVIC_SetPriority(USART2_IRQn, 15, 0);


}*/


int _write(int fd, char* ptr, int len)
{
	HAL_StatusTypeDef hstatus;

	if (fd == STDOUT_FILENO || fd == STDERR_FILENO)
	{
		hstatus = HAL_UART_Transmit(&gHuart, (uint8_t *) ptr, len, HAL_MAX_DELAY);
		if (hstatus == HAL_OK)
			return len;
		else
			return EIO;
	}
	errno = EBADF;
	return -1;
}



int _read(int fd, char* ptr, int len) {
	HAL_StatusTypeDef hstatus;

	if (fd == STDIN_FILENO) {
		hstatus = HAL_UART_Receive(&gHuart, (uint8_t *) ptr, 1, HAL_MAX_DELAY);
		if (hstatus == HAL_OK)
			return 1;
		else
			return EIO;
	}
	errno = EBADF;
	return -1;
}




