// reverse k-length string per 2k- Group  l-541
// 若剩下的<k,reverse all; 剩下的∈[k,2k),reverse 前k
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string reverseII(string s, int k);

int main()
{

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