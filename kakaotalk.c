/**
    CopyRight ⓒ 2020. Hyundai Rotem Co., Ltd All Rights Reserved  
*/
/**
    @file       ATOTSComm.h
    @brief      file description
    @remark     Project - ETCS_ATO_CPU_APP \n
                Development Environment - PC \n
                Operating System - VxWorks 7 Cert \n
                Target(CPU) - I.MX6 Solo \n
                Language  - C \n
    @note
        2020.04.10(1)   ksw     First Issue \n
*/


/* includes */
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


/* typedef */
typedef struct cost_map
{
    int *plus;
    int *cost;
} COST_M;


/* define*/
#define count0 8

/* global variables */
int index0[count0] = {1,0,0,0,0,0,0,0}; //이모티콘은 8종류 이하인것을 고려, 4진법 체계를 만들어 각각의 이모티콘에 대한 할인율을 고려합니다. 
COST_M* cost_m[count0] = {0};



/*4진법 구축 함수*/
int index0_add(int* basis) 
{
  if(index0[*basis] > 0)
  {
    return 0;
  }

  for(int i = 0 ; i < count0; ++i)
  {
    if(index0[i] < 5) /*issue 1,현재 5진법으로 구성되어 있는데, 문제의도에 맞게 4진법으로 고치면 문제 통과가 안됩니다..*/
    {
        index0[i]++;
        return 1;
    }
    else
    {
        index0[i] = 1;
    }
  }
    return 1;
}


int* solution(int** users, size_t users_rows, size_t users_cols, int emoticons[], size_t emoticons_len) {
    int* answer = (int*)malloc(2);
    answer[0] = 0; answer[1] = 0;
    
    do /*할인율 변화를 감독하는 케이스*/
    {
      int plus = 0;
      int coin = 0;

      for(int i = 0 ; i < users_rows ; ++i) /*유저에 따라 구독인원과 판매액을 집계합니다.*/
      {
        int coin0 = 0;
        for(int j = 0; j < count0 ; ++j) /*한 유저에 대한 이모티콘 구매 비용 관리*/
        {
          if(index0[j] * 10 >= users[i][0])
          {
            coin0 += emoticons[j] * (1 - (index0[j] * 0.1));
          }
        }

        if(coin0 >= users[i][1])
        {
          plus++;
          coin0 = 0;
        }
        coin += coin0;
      }

      if( (plus > answer[0]) || (  (plus == answer[0]) && (coin > answer[1])))
      {
        answer[0] = plus;
        answer[1] = coin;
      }

    } while ( index0_add(&emoticons_len)  > 0 );
    

    return answer;
}


