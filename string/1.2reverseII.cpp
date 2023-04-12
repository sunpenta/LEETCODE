// reverse k-length string per 2k- Group  l-541
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
            reverse(s.begin()+i, s.begin()+k);
    }
    return s;
}