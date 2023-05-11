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

/* typedef */
typedef struct race
{
    int velo;
    int tag;
    int weig;

} RACE;


/* define*/
#define speed_rg 1001

/* global variables */
int tc = 0;
RACE race[speed_rg] = {0};


/*차량 번호의 합을 구함*/
int race_result()
{
    int result = 0;
    for(int i = 1; i < speed_rg ; ++i)
    {
        result += race[i].tag;
    }

    return result;
}

int main() {
	
    scanf("%d", &tc);

    for(int i = 1; i <= tc ; ++i) /*속도를 인덱스로 내구도가 가장 좋은 차량의 번호를 기록*/
    {
       int v,w; 
       scanf("%d %d", &v, &w); 
       
       if(race[v].weig <= w){
        race[v].tag = i;
        race[v].weig = w;
       }
    }

    printf("%d", race_result());
	return 0;
}
