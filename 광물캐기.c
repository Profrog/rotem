/* includes */
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

/* define*/
#define MINE_KIND 3 /*광물의 종류 0 = diamond, 1 = iron, 2 = stone*/
const char* mine_list[MINE_KIND] = {"diamond", "iron", "stone"};

/* typedef */
typedef struct value0
{
  int mh_score[MINE_KIND];
  int iMineNum;
}VALUE0;

/* global variables */
int mine_map[MINE_KIND][MINE_KIND] = {{1,1,1}, {5,1,1}, {25,5,1}};
int* pick_list = {0};


/* 

@fn     int CheckMine(char* mineName)
@brief  광물이름에 해당하는 인덱스값을 리턴한다(diamond = 0 , iron = 1 , stone = 2 )
@param  mineName : 광물명
@return i :  광물 인덱스 값, -1 : 에러코드

*/
int CheckMine(char* mineName)
{
  for(int i = 0; i < MINE_KIND ; ++i) 
  {
    if(*mineName == *mine_list[i])
    {
        return i;
    }
  }

  return -1;
}


/*

@fn int* CheckPicks(int* picks,int iPicksSize)
@brief  diamond > iron > stone 의 우선순위를 가지는 인덱스 값을 곡괭이 개수 만큼 가지는 array를 만든다.
@param  picks : 곡괭이_개수 배열, iPicksSize : 모든 종류의 곡괭이 개수의 합
@return pick_list0 : 곡괭이 인덱스_곡괭이 인덱스 개수 배열

*/
int* CheckPicks(int* picks,int iPicksSize)
{
  int* pick_list0 = calloc(iPicksSize, sizeof(int));

  for(int i = 0, k = 0; i < MINE_KIND; ++i) /* 각 곡괭이의 개수만큼의 길이를 가짐 */
  {
    for(int j = 0 ; j < picks[i]; ++j, ++k)
    {
        pick_list0[k] = i;
    }
  }

  return pick_list0;
}



/* 

@fn int solution(int picks[], size_t picks_len, const char* minerals[], size_t minerals_len)
@brief  phase 1 : 곡괭이 3종류에 대하여 , 5개들이 묶음을 해당 곡괭이로 캤을때 비용계산
        phase 2 : 지정된 5개 들이 묶음을 최적의 곡괭이에 배치
        phase 3 : 배치된 비용들의 합을 계산
@param  곡괭이 종류 및 개수, 광물 종류 및 개수
@return iAnswer : 최적 비용계산
*/
int solution(int picks[], size_t picks_len, const char* minerals[], size_t minerals_len)
{
   int iAnswer = 0; 
   int iDummySize = (minerals_len/5) + (minerals_len%5 > 0?1:0);
   int iAllPicks = picks[0] + picks[1] + picks[2];
   int iRunoutT = (iDummySize < iAllPicks)? iDummySize : iAllPicks;

   VALUE0* value0 = calloc(iDummySize, sizeof(VALUE0));
   int* pick_list = CheckPicks(picks, iAllPicks);

  /*phase 1*/
   for(int i = 0, k = 0; (i < iDummySize) && (k < minerals_len); ++i) /* i : 5개들이 광물 컨트롤, k : 전체 광물 컨트롤 */
  {
   {
    for(int j = 0; (j < 5) && (k < minerals_len) ; ++j, ++k) /*j : 5개 들이 내부의 광물 컨트롤 */
    {
       int index2 =  CheckMine(minerals[k]);
       
       for(int k = 0; k < MINE_KIND; ++k) /*곡괭이 별로 캤을 때 광물 비용을 저장*/
        {
          value0[i].mh_score[k] += mine_map[k][index2];
        }

        ++value0[i].iMineNum;
    }
   }
   /*phase 1*/

  /*phase 2*/
   for(int i = 0; i < iRunoutT; ++i) /* i : 광물 5개 들이 묶음이나 곡괭이 개수 중 더 작은 쪽*/
   {
    for(int j = i+1; j < iRunoutT; ++j) /* j : 광물 5개 들이 묶음이나 곡괭이 개수 중 더 작은 쪽*/
    { 
         for(int k = MINE_KIND-1; k >= 0; --k) /*k : 다이아몬드 -> 철 -> 돌 */
         {
          if(value0[i].mh_score[k] - value0[i].iMineNum < value0[j].mh_score[k] - value0[j].iMineNum)
          {
            VALUE0 change = value0[i];
            value0[i] = value0[j];
            value0[j] = change;
            break;
          }
         }
    }
   }
  }
  /*phase 2*/

   /*phase 3*/
   for(int i = 0; i < iRunoutT; ++i) /* i : 광물 5개 들이 묶음이나 곡괭이 개수 중 더 작은 쪽*/
   {
    iAnswer += value0[i].mh_score[pick_list[i]];
   }
   /*phase 3*/
  
    return iAnswer;
}
