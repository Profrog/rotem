#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define m_n 3 /*광물의 종류 0 = diamond, 1 = iron, 2 = stone*/
const char* mine_list[m_n] = {"diamond", "iron", "stone"};

typedef struct value0
{
  int mh_score[m_n];
  int mine_num;
}VALUE0;

int mine_map[m_n][m_n] = {{1,1,1}, {5,1,1}, {25,5,1}};
int* pick_list = {0};

int check_mine(char* name)
{
  for(int i = 0; i < m_n ; ++i)
  {
    if(*name == *mine_list[i])
    {
        return i;
    }
  }

  return -1;
}

int* check_picks(int* picks,int picks_size)
{
  int* pick_list0 = calloc(picks_size, sizeof(int));

  for(int i = 0, k = 0; i < m_n; ++i)
  {
    for(int j = 0 ; j < picks[i]; ++j, ++k)
    {
        pick_list0[k] = i;
    }
  }

  return pick_list0;
}


int solution(int picks[], size_t picks_len, const char* minerals[], size_t minerals_len)
{
   int answer = 0; 
   int dummy_size = (minerals_len/5) + (minerals_len%5 > 0?1:0);
   int all_picks = picks[0] + picks[1] + picks[2];
   int runout_t = (dummy_size < all_picks)? dummy_size : all_picks;

   VALUE0* value0 = calloc(dummy_size, sizeof(VALUE0));
   int* pick_list = check_picks(picks, all_picks);

   for(int i = 0, k = 0; (i < dummy_size) && (k < minerals_len); ++i)
   {
    for(int j = 0; (j < 5) && (k < minerals_len) ; ++j, ++k)
    {
       int index2 =  check_mine(minerals[k]);
       
       for(int k = 0; k < m_n; ++k) /*곡괭이 종류 별로 캤을 때*/
        {
          value0[i].mh_score[k] += mine_map[k][index2];
        }

        ++value0[i].mine_num;
    }

   }

   for(int i = 0; i < runout_t; ++i)
   {
    for(int j = i+1; j < runout_t; ++j)
    { 
         for(int k = m_n-1; k >= 0; --k)
         {
          if(value0[i].mh_score[k] - value0[i].mine_num < value0[j].mh_score[k] - value0[j].mine_num)
          {
            VALUE0 change = value0[i];
            value0[i] = value0[j];
            value0[j] = change;
            break;
          }
         }
    }
   }
   
   for(int i = 0; i < runout_t; ++i)
   {
    answer += value0[i].mh_score[pick_list[i]];
   }
  
    return answer;
}
