// 赢比赛所需最少时间 - 贪心  l-2383   -jump/1 & 2
// energy和experience严格大于才可击败对手；每击败1个对手，energy减，experience加
#include <bits/stdc++.h>
using namespace std;
int minHours(int initialEnergy, int initialExperience, vector<int>& energy, vector<int>& experience);

int main()
{
    int initialEnergy = 5, initialExperience = 3;
    vector<int>energy={1,4,3,2}, experience={2,6,3,1}; // 输入
    cout<<minHours(initialEnergy,initialExperience,energy,experience)<<endl; // 输出:8
    return 0;
}

int minHours(int initialEnergy,int initialExperience,vector<int>&energy,vector<int>& experience)
{
    int hours=0;
    for (int i=0;i<energy.size();i++)
    {
        if (initialEnergy<=energy[i])
        {
            hours+=energy[i]-initialEnergy+1;
            initialEnergy=energy[i]+1; // 严格>
        }
        initialEnergy-=energy[i];
    }

    for (int i=0;i<experience[i];i++)
    {
        if (initialExperience<=experience[i])
        {
            hours+=experience[i]-initialExperience+1;
            initialExperience=experience[i]+1;
        }
        initialExperience+=experience[i];
    }
    return hours;
}