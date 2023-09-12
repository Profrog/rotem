/**
    CopyRight ⓒ 2023. Hyundai Rotem Co., Ltd All Rights Reserved  
*/
/**
    @file       Aug_Task_00.c
    @brief      file description
    @remark     Project - SW Coding Master Aug Task \n
                Development Environment - PC \n
                Language  - C \n
    @note				과제명: 8월_방문길이 \n
*/

/* includes */
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

/* global variables */
const int NUM_mArrow = 4;
const int MIN_INDEX = 0;
const int MAX_INDEX = 11;

int mMap[11][11][4];
int mCurIndex[2];
int mArrow[4][2]; /*0:U ,1:D ,2:R ,3:L */
char mArrow_list[4];
int mAnswer;

/* 
@fn     bool OverSize(int *alpa)
@brief  로봇이 좌표 평면을 넘어갔는 지를 검사
@param  mineName : (-5,-5) ~ (5,5) 인덱스를 벗어나면 false, 그렇지 않으면 true를 return 한다
@return i :  false/true
*/
bool OverSize(int *alpa)
{
  bool mAnswer0 = true;  
      
  if((MIN_INDEX <= alpa[0]) && (alpa[0] < MAX_INDEX))
  {
    if((MIN_INDEX <= alpa[1]) && (alpa[1] < MAX_INDEX))
    {
        mAnswer0 = false;
    }
  }
    
  return mAnswer0;
}




/* 
@fn     int CheckIndex(int alpa)
@brief  U:0와 D:1을 서로 교환, 2:R과 3:L을 서로 교환하여 반환한다.(움직인 후,지나간 경로를 다시 밟지 않기 위함)
@param  2*(alpa/2) + (1 - alpa%2)
@return 2*(alpa/2) + (1 - alpa%2)
*/
int CheckIndex(int alpa)
{
  return (2*(alpa/2)) + (1 - (alpa%2));
}



/* 
@fn     bool MovingMap(char alpa)
@brief  현재 위치에서 다음 위치로 움직이면서 지나간 위치는 value 값을 올려 기록한다.
@param  2*(alpa/2) + (1 - alpa%2)
@return false/true
*/
bool MovingMap(char alpa)
{
  bool mAnswer0 = false;
    
  for(int Idx = 0; Idx < NUM_mArrow ;++Idx)
  {
    if(alpa == mArrow_list[Idx])
    {
      
      int beta[2] = {mCurIndex[0] + mArrow[Idx][0], mCurIndex[1] + mArrow[Idx][1]};
    
      if(OverSize(beta))
      {
        --mAnswer;  
        break;
      }
      
      else
      {
          if((mMap[mCurIndex[0]][mCurIndex[1]][Idx] > 0) && (mMap[beta[0]][beta[1]][CheckIndex(Idx)] > 0))
          {
            --mAnswer;
          }

          ++mMap[mCurIndex[0]][mCurIndex[1]][Idx];
          ++mMap[beta[0]][beta[1]][CheckIndex(Idx)];
          mCurIndex[0] = beta[0];
          mCurIndex[1] = beta[1];    
          mAnswer0 =  true;
      }
    }
  }
    
  return mAnswer0;  
}


/* 
@fn     int solution(const char* dirs)
@brief  데이터 초기화 및 하부 함수 호출 제어
@param  mAnswer
@return false/true
*/
int solution(const char* dirs) {
    
    mCurIndex[0] = 5;
    mCurIndex[1] = 5;
    
    mArrow[0][0] = 0;
    mArrow[0][1] = 1;   
    mArrow[1][0] = 0;
    mArrow[1][1] = -1;
    
    mArrow[2][0] = 1;
    mArrow[2][1] = 0;
    mArrow[3][0] = -1;
    mArrow[3][1] = 0;
        
    mArrow_list[0] = 'U';
    mArrow_list[1] = 'D';
    mArrow_list[2] = 'R';
    mArrow_list[3] = 'L';
 
    mAnswer = (int)(strlen(dirs));
    for(int Idx = 0; Idx < (int)(strlen(dirs));++Idx)
    {
      MovingMap(dirs[Idx]);
    }
    
    return mAnswer;
}

int main(void)
{
  printf("%d", solution("ULURRDLLU"));
  return 0;
}
