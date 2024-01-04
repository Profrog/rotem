
/**
    CopyRight ⓒ 2023. Hyundai Rotem Co., Ltd All Rights Reserved  
*/
/**
    @file       MONTH_H.h
    @brief      file description
    @remark     Project - ETCS_ATO_CPU_APP \n
                Development Environment - PC \n
                Operating System - VxWorks 7 Cert \n
                Target(CPU) - I.MX6 Solo \n
                Language  - C \n
    @note
        2023.09.13(1)   kmg     First Issue \n
*/

#ifndef MONTH_H
#define MONTH_H

/* includes */
#include "stdio.h"
#include "stdbool.h"
#include "stdlib.h"
#include "string.h"

/* defines */
#define NUM_MARROW (4)

typedef char                CHAR;
typedef signed int          INT32;

/* function declarations */
INT32 GetOverSize(INT32 *iIndex);
INT32 GetCheckIndex(INT32 iReverse);
INT32 SetMovingMap(CHAR cCurrentIndex);

#endif MONTH_H
