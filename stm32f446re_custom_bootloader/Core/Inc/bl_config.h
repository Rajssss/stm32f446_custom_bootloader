/*
 * bl_config.h
 *
 *  Created on: 07-Mar-2021
 *      Author: Raj.S
 */

#ifndef INC_BL_CONFIG_H_
#define INC_BL_CONFIG_H_

/*
 * General configurations
 */
//Note: Sector 2-7 = user app
#define 	FLASH_SECTOR_2_BASE_ADDRESS		0x08008000
//Debug & port config
#define 	BL_DEBUG_PORT						//enable UART debug port
#define 	UART_DEBUG_PORT		&huart2			//use UART2 as debug port
#define 	UART_CMD_PORT		&huart3			//use UART3 as command port

/*
 * Supported bootloader commands
 */
//This command is used to read the bootloader version from the MCU
#define 	BL_GET_VER				0x51

//This command is used to know what are the commands supported by the bootloader
#define 	BL_GET_HELP				0x52

//This command is used to read the MCU chip identification number
#define 	BL_GET_CID				0x53

//This command is used to read the FLASH Read Protection level.
#define 	BL_GET_RDP_STATUS		0x54

//This command is used to jump bootloader to specified address.
#define 	BL_GO_TO_ADDR			0x55

//This command is used to mass erase or sector erase of the user flash .
#define 	BL_FLASH_ERASE          0x56

//This command is used to write data in to different memories of the MCU
#define 	BL_MEM_WRITE			0x57

//This command is used to enable or disable read/write protect on different sectors of the user flash .
#define 	BL_EN_RW_PROTECT		0x58

//This command is used to read data from different memories of the microcontroller.
#define 	BL_MEM_READ				0x59

//This command is used to read all the sector protection status.
#define 	BL_READ_SECTOR_P_STATUS	0x5A


//This command is used to read the OTP contents.
#define 	BL_OTP_READ				0x5B


//This command is used disable all sector read/write protection
#define 	BL_DIS_R_W_PROTECT		0x5C

/*uint8_t supported_commands[] = {
		BL_GET_VER ,
		BL_GET_HELP,
		BL_GET_CID,
		BL_GET_RDP_STATUS,
		BL_GO_TO_ADDR,
		BL_FLASH_ERASE,
		BL_MEM_WRITE,
		BL_READ_SECTOR_P_STATUS};*/

/*
 * Bootloader ACK & NACK Bytes
 */
#define 	BL_ACK					0xA5
#define 	BL_NACK					0x7F

/*
 * CRC
 */
#define 	VERIFY_CRC_FAIL    		0x01
#define 	VERIFY_CRC_SUCCESS 		0x00

#endif /* INC_BL_CONFIG_H_ */
