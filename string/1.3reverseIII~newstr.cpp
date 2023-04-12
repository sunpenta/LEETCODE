// reverse words in string - stringstream l-557
// 时间复杂度:
#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;
string reverseWords(string s);

int main()
{
    string s="s'teL ekat edoCteeL tsetnoc"; // input
    cout<<reverseWords(s)<<endl; // output
}

string reverseWords(string s)
{
    stringstream ss(s);
    string str, res="";
    while (ss>>str)
    {
        reverse(str.begin(), str.end());
        res+=str+' ';
    }
    res.pop_back();
    return res;
}