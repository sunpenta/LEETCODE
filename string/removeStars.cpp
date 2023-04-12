// 移除'*' - newstr  l-2390
// 移除'*'和它相邻左边的非'*'字母，； 时间复杂度:O(n) 空间复杂度:O(1)
#include <iostream>
using namespace std;
string removeStars(string s);

int main()
{

}

string removeStars(string s)
{
    int n=s.length();
    string res="";
    for (int i=0; i<n; i++)
    {
        if (s[i]!='*')
            res+=s[i];
        else
            s.pop_back();
    }
    return res;
}