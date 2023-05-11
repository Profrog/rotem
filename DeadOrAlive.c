#include <stdio.h>

typedef struct race
{
    int velo;
    int tag;
    int weig;

} RACE;

//구조체 구조

int tc = 0;
#define speed_rg 1001
RACE race[speed_rg] = {0};

//전역변수

int race_result()
{
    int result = 0;
    for(int i = 1; i < speed_rg ; ++i)
        result += race[i].tag;

    return result;
}

int main() {
	
    scanf("%d", &tc);

    for(int i = 1; i <= tc ; ++i)
    {
       int v,w; 
       scanf("%d %d", &v, &w); //한 속도에 한대의 차량만 살아남기
       
       if(race[v].weig <= w){
        race[v].tag = i;
        race[v].weig = w;
       }
    }

    printf("%d", race_result());
	return 0;
}
