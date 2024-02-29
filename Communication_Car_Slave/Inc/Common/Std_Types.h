/*
 * Std_Types.h
 *
 *  Created on: Jan 28, 2024
 *      Author: Lenovo
 */

#ifndef STD_TYPES_H_
#define STD_TYPES_H_
typedef unsigned long uint32_t;
typedef unsigned char uint8_t;
typedef unsigned short uint16_t;

#define NULL (void *)0

typedef enum
{
	HAL_OK = 0x00U,
	HAL_NOT_OK = 0x01U,
}HAL_State;
#endif /* STD_TYPES_H_ */
