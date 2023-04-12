// reverse k-length string per 2k-Group - 原地 l-541
// 若剩下的<k,reverse all; 剩下的∈[k,2k),reverse 前k;  时间复杂度:O(n) 空间复杂度:O(1)
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string reverseII(string s, int k);

int main()
{
    string s="bacdfeg"; int k=2; // input
    cout<<reverseII(s,k)<<endl; // output
}

string reverseII(string s, int k)
{
    int n=s.length();
    for (int i=0; i<n; i+=2*k)
    {
        if (n-i<k)
            reverse(s.begin()+i,s.end());
        else
            reverse(s.begin()+i, s.begin()+i+k); // [i,i+k)
    }
    // 同 reverse(s.begin(),min(s.end(), s.begin()+i+k));
    return s;
}