/**
*   @file    can_T.h
*   @brief   
*   @details 
*/

#ifndef CAN_T_H
#define CAN_T_H

#include "stdint.h"
#include "s32k144_T.h"

/*----------------------- MODE ------------------------*/
/*
    *  @brief  CAN_Enter_FreezeMode
    *  @details  This function enters the freeze mode of the CAN module by doing the following
    *            in "55.1.9.1 Freeze mode entry"
*/

void CAN_init(CAN_Type *hcan, uint32_t bit_rate_conf);
void CAN_transmit_msg(CAN_Type *hcan); 
void CAN_receive_msg(uint32_t Rx_data[2]);
void CAN_send_msg(CAN_Type *hcan, uint32_t msg[2], uint8_t DLC);

#endif /* CAN_T_H */