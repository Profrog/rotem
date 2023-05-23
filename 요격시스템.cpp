#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool cmp(vector<int> &v1, vector<int> &v2)
{
    if(v1[0] == v2[0])
      return v1[1] < v2[1];

    else
     return  v1[0] < v2[0];
}

int solution(vector<vector<int>> targets) {
    int answer = 0;
    int line = -1;

    sort(targets.begin(), targets.end(), cmp);

    for(auto a : targets)
    {   
        if(a[0] > line)
        {
            ++answer;
            line = a[1] - 1;
        } 

        else
        {
           line = (line < a[1] - 1) ? line : (a[1] - 1);
        }
    }

    return answer;
}
