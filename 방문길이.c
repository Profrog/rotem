/* includes */
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

/* global variables */
const int kind_arrow = 4;
const int min_s = 0;
const int max_s = 11;

int map0[max_s][max_s][kind_arrow] = {0};
int current_p[] = {5,5};
int arrow[kind_arrow][2] = {{0,1},{0,-1},{1,0},{-1,0}}; /*0:U ,1:D ,2:R ,3:L */
char arrow_list[] = {'U', 'D', 'R', 'L'};
int answer = 0;


/* 
@fn     bool OverSize(int *alpa)
@brief  로봇이 좌표 평면을 넘어갔는 지를 검사
@param  mineName : (-5,-5) ~ (5,5) 인덱스를 벗어나면 false, 그렇지 않으면 true를 return 한다
@return i :  false/true
*/
bool OverSize(int *alpa)
{
      
  if((min_s <= alpa[0]) && (alpa[0] < max_s))
  {
    if((min_s <= alpa[1]) && (alpa[1] < max_s))
    {
      return false;
    }
  }
    
  return true;
}



/* 
@fn     int CheckIndex(int alpa)
@brief  U:0와 D:1을 서로 교환, 2:R과 3:L을 서로 교환하여 반환한다.(움직인 후,지나간 경로를 다시 밟지 않기 위함)
@param  2*(alpa/2) + (1 - alpa%2)
@return 2*(alpa/2) + (1 - alpa%2)
*/
int CheckIndex(int alpa)
{
  return 2*(alpa/2) + (1 - alpa%2);
}



/* 
@fn     bool MovingMap(char alpa)
@brief  현재 위치에서 다음 위치로 움직이면서 지나간 위치는 value 값을 올려 기록한다.
@param  2*(alpa/2) + (1 - alpa%2)
@return false/true
*/
bool MovingMap(char alpa)
{
  for(int i = 0; i < kind_arrow ;++i)
  {
    if(alpa == arrow_list[i])
    {
      
      int beta[2] = {current_p[0] + arrow[i][0], current_p[1] + arrow[i][1]};
    
      if(OverSize(&beta))
      {
        --answer;  
        return false;
      }
      
      if((map0[current_p[0]][current_p[1]][i] > 0) && (map0[beta[0]][beta[1]][CheckIndex(i)] > 0))
      {
        --answer;
      }
      
      ++map0[current_p[0]][current_p[1]][i];
      ++map0[beta[0]][beta[1]][CheckIndex(i)];
      current_p[0] = beta[0];
      current_p[1] = beta[1];    
      return true;
    }
  }
}


int solution(const char* dirs) {
    answer = strlen(dirs);
    for(int i = 0; i < strlen(dirs);++i)
    {
      MovingMap(dirs[i]);
    }
    
    return answer;
}
