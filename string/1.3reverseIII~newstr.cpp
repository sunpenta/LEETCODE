// reverse words in string - stringstream + newstr l-557
// slower than inplace 时间复杂度:
#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;
string reverseWords(string s);

int main()
{
    string s="s'teL ekat edoCteeL tsetnoc"; // input
    cout<<reverseWords(s)<<endl; // output:"Let's take LeetCode contest"
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