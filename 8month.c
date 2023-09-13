/**
    CopyRight ⓒ 2023. Hyundai Rotem Co., Ltd All Rights Reserved
*/
/**
    @file       8month.c
    @brief      This source file is CodingMaster task from September
    @remark     Project - CodingMaster
                Development Environment - PC
                Language  - C
    @note
        2023.09.13  kmg     first Issue
*/


/* global variables */
static INT32 MIN_INDEX = 0;
static INT32 MAX_INDEX = 11;

/* local variables */
INT32 iMap[11][11][4];
INT32 iCurIndex[2];
INT32 iArrow[4][2]; /*0:U ,1:D ,2:R ,3:L */
CHAR iArrow_list[4];
UINT32 iAnswer = 0U;

/* includes */
#include "MONTH_H.h"

/* defines */
#define NUM_MARROW (4)

/* function declarations */
INT32 solution(const CHAR* dirs) ;


typedef enum index2
{
  Zero = 0, 
  One, 
  Two, 
  Three
} INDEX;

typedef void                VOID;
typedef unsigned int        UINT32;

/* 
@fn     INT32 OverSize(INT32 *iIndex)
@brief  로봇이 좌표 평면을 넘어갔는 지를 검사
@param  mineName : (-5,-5) ~ (5,5) 인덱스를 벗어나면 false, 그렇지 않으면 true를 return 한다
@return i :  false/true
*/

INT32 GetOverSize(INT32 *iIndex)
{
  INT32 iAnswer0 = 1, iAnswer1 = 1;  
      
  if((MIN_INDEX <= iIndex[0]) && (iIndex[0] < MAX_INDEX))
  {
    if((MIN_INDEX <= iIndex[1]) && (iIndex[1] < MAX_INDEX))
    {
        iAnswer0 = 0;
    }
  }
    
  return iAnswer0;
}

/* 
@fn     INT32 CheckIndex(INT32 alpa)
@brief  U:0와 D:1을 서로 교환, 2:R과 3:L을 서로 교환하여 반환한다.(움직인 후,지나간 경로를 다시 밟지 않기 위함)
@param  2*(alpa/2) + (1 - alpa%2)
@return 2*(alpa/2) + (1 - alpa%2)
*/

INT32 GetCheckIndex(INT32 iReverse)
{
  return (2*(iReverse/2)) + (1 - (iReverse%2));
}

/* 
@fn     INT32 MovingMap(CHAR cCurrentIndex)
@brief  현재 위치에서 다음 위치로 움직이면서 지나간 위치는 value 값을 올려 기록한다.
@param  2*(alpa/2) + (1 - alpa%2)
@return false/true
*/

INT32 SetMovingMap(CHAR cCurrentIndex)
{
  INT32 iAnswer0 = 0;
    
  for(INT32 Idx = 0; Idx < NUM_MARROW ;++Idx)
  {
    if(cCurrentIndex == iArrow_list[Idx])
    {
      
      INT32 ibeta[2] = {iCurIndex[0] + iArrow[Idx][0], iCurIndex[1] + iArrow[Idx][1]};
    
      if(OverSize(ibeta))
      {
        --iAnswer;  
        break;
      }
      
      else
      {
          if((iMap[iCurIndex[0]][iCurIndex[1]][Idx] > 0) && (iMap[ibeta[0]][ibeta[1]][CheckIndex(Idx)] > 0))
          {
            --iAnswer;
          }

          ++iMap[iCurIndex[0]][iCurIndex[1]][Idx];
          ++iMap[ibeta[0]][ibeta[1]][CheckIndex(Idx)];
          iCurIndex[0] = ibeta[0];
          iCurIndex[1] = ibeta[1];    
          iAnswer0 =  1;
      }
    }
  }
    
  return iAnswer0;  
}

/* 
@fn     INT32 solution(const CHAR* dirs)
@brief  데이터 초기화 및 하부 함수 호출 제어
@param  mAnswer
@return false/true
*/

INT32 solution(const CHAR* dirs) {
    
    iCurIndex[0] = 5;
    iCurIndex[1] = 5;
    
    iArrow[0][0] = 0;
    iArrow[0][1] = 1;   
    iArrow[1][0] = 0;
    iArrow[1][1] = -1;
    
    iArrow[2][0] = 1;
    iArrow[2][1] = 0;
    iArrow[3][0] = -1;
    iArrow[3][1] = 0;
        
    iArrow_list[0] = 'U';
    iArrow_list[1] = 'D';
    iArrow_list[2] = 'R';
    iArrow_list[3] = 'L';
 
    iAnswer = ((INT32)(strlen(dirs)) > 0) ? (INT32)(strlen(dirs)) : 0;
    for(INT32 Idx = 0; Idx < (INT32)(strlen(dirs));++Idx)
    {
      MovingMap(dirs[Idx]);
    }
    
    return iAnswer;
}

