// flip string 使它单调递增 -dp  l-926
#include <iostream>
using namespace std;
int minFlip(string s);

int main()
{
    string s="0011101"; // input
    cout<<minFlip(s)<<endl; // output:1  0011111
    return 0;
}

int minFlip(string s)
{
    int count_one=0, count_flip=0;
    for (char ch:s)
    {
        if (ch=='1')
            ++count_one;
        else
            ++count_flip;
        count_flip=min(count_flip,count_one);
    }
    return count_flip;
}