/*
 * cmd_process.c
 *
 *  Created on: 07-Mar-2021
 *      Author: Raj.S
 */
#include "main.h"


void bootloader_handle_getver_cmd(uint8_t *pBuff)
{
	if (! bootloader_verify_crc(pBuff, len, crc_host)) {

	} else {

	}
}

void bootloader_handle_gethelp_cmd(uint8_t *pBuff)
{

}

void bootloader_handle_getcid_cmd(uint8_t *pBuff)
{

}

void bootloader_handle_getrdp_cmd(uint8_t *pBuff)
{

}

void bootloader_handle_go_cmd(uint8_t *pBuff)
{

}

void bootloader_handle_flash_erase_cmd(uint8_t *pBuff)
{

}

void bootloader_handle_mem_write_cmd(uint8_t *pBuff)
{

}

void bootloader_handle_en_rw_protect(uint8_t *pBuff)
{

}

void bootloader_handle_mem_read (uint8_t *pBuff)
{

}

void bootloader_handle_read_sector_protection_status(uint8_t *pBuff)
{

}

void bootloader_handle_read_otp(uint8_t *pBuff)
{

}

void bootloader_handle_dis_rw_protect(uint8_t *pBuff)
{

}


/*
 * Some Helper functions
 */
uint8_t bootloader_verify_crc(uint8_t *pData, uint32_t len, uint32_t crc_host)
{
    uint32_t uwCRCValue=0xff;

    for (uint32_t i=0 ; i < len ; i++)
	{
        uint32_t i_data = pData[i];
        uwCRCValue = HAL_CRC_Accumulate(&hcrc, &i_data, 1);
	}

	 /* Reset CRC Calculation Unit */
    __HAL_CRC_DR_RESET(&hcrc);

	if( uwCRCValue == crc_host)
	{
		return VERIFY_CRC_SUCCESS;
	}

	return VERIFY_CRC_FAIL;
}

void bootloader_send_ack(uint8_t cmd_code, uint8_t follow_len)
{
	uint8_t buff[2];
	buff[0] = BL_ACK;
	buff[1] = follow_len;
	HAL_UART_Transmit(UART_CMD_PORT, buff, 2, HAL_MAX_DELAY);
}

void bootloader_send_ack(void)
{
	uint8_t buff = BL_NACK;
	HAL_UART_Transmit(UART_CMD_PORT, &buff, 1, HAL_MAX_DELAY);
}

void bootloader_uart_write_data(uint8_t *pBuff,uint32_t len)
{
    /* you can replace the below ST's USART driver API call with your MCUs driver API call */
	HAL_UART_Transmit(C_UART,pBuffer,len,HAL_MAX_DELAY);

}

uint8_t bootloader_get_version(void)
{
  return (uint8_t)BL_VERSION;
}
