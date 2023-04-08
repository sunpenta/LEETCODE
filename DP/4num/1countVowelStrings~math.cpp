// 字典序元音字符串的组合数-可重组合数  l-1641
// 字符串长度为n,仅由元音(a,e,i,o,u)组成，按字典序排列; 元素可重复使用; n∈[1,50]
#include <iostream>
using namespace std;
int countVowelStrings(int n);

int main()
{
    int n=2; // 输入
    cout<<countVowelStrings(n)<<endl; // 输出:15 {"aa","ae","ai","ao","au","ee","ei","eo","eu",...}
    system("pause");
}
// C(n+r-1,r)
int countVowelStrings(int n)
{
    return (n+4)*(n+3)*(n+2)*(n+1)/24;
}