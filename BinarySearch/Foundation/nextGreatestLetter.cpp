// 下一个最大字母  l-744  - 桶
// -> 存在，下一个最大字母;否则，第一个字母
#include <iostream>
#include <vector>
using namespace std;
char nextGreatestLetter(vector<char>& letters, char target);

int main()
{
    vector<char> letters={'x', 'x', 'y', 'y'}; char target='z'; // input
    char res=nextGreatestLetter(letters, target); // output: 'x'
    cout<<res<<endl;
    return 0;
}

char nextGreatestLetter(vector<char>& letters, char target)
{
    int left=0, right=letters.size();
    while (left<right)
    {
        int mid=(left+right)/2;
        if (letters[mid]<=target)
            left=mid+1;
        else
            right=mid;
    }
    return left==letters.size()? letters[0]: letters[left];
}