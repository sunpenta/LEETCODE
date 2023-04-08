// 文本左右对齐-分类模拟 l-68
// 1 <= words.length <= 300; 1 <= words{i}.length <= 20; 1 <= maxWidth <= 100
#include <bits/stdc++.h>
using namespace std;
vector<string> fullJustify(vector<string>&words,int maxWidth);

int main()
{
    vector<string>words={"This", "is", "an", "example", "of", "text", "justification."};
    int maxWidth=16; // 输入
    vector<string>ans=fullJustify(words,maxWidth); // 输出: {"This    is    an", 
    for (auto str:ans)                             //        "example of  text", 
        cout<<"\""<<str<<"\""<<endl;               //        "justification.  "}*/ 
    system("pause");  
}

// 用space把[left,right)的单词拼接
string join(vector<string>&words,int left,int right,string space)
{
    string joined=words[left];
    for (int i=left+1;i<right;i++) // 注意下标起始是left+1
    {
        joined+=space+words[i];
    }
    return joined;
}

vector<string> fullJustify(vector<string>&words,int maxWidth)
{
    int n=words.size();
    int right=0; // words的下标
    vector<string>ans; // 文本对齐后结果
    while (true) // 循环
    {
        int left=right; // 每一行第1个单词下标
        
        // 计算每行的单词长度
        int sumlen=0;
        while (right<n && sumlen+words[right].size()+right-left<=maxWidth) // 注意单词之间至少有1个空格
        {
            sumlen+=words[right++].size();
        }
        int spaces=maxWidth-sumlen; // 空格数
        int numwords=right-left; // 单词数
        // 最后一行，左对齐; 注意放在计算单词长度后面
        string s;
        if (right==n)
        {
            s=join(words,left,n," ");
            s+=string(maxWidth-s.length(),' ');
            ans.emplace_back(s);
            return ans;
        }
        // 中间行只有1个单词,左对齐
        if (numwords==1)
        {
            ans.emplace_back(words[left]+string(spaces,' '));
            continue;
        }
        // 中间行多于1个单词
        int avrspace=spaces/(numwords-1); // 平均空格
        int extraspace=spaces%(numwords-1); // 额外空格
        s=join(words,left,left+extraspace+1,string(avrspace+1,' '));
        s+=string(avrspace,' ')+join(words,left+extraspace+1,right,string(avrspace,' '));//注意中间夹空格数
        ans.emplace_back(s);
    }
}
