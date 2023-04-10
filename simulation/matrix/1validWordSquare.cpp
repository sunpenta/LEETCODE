// valid word square-simulation  l-422
#include <bits/stdc++.h>
using namespace std;
bool validWordSquare(vector<string>& words);

int main()
{
    vector<string> words = {"abcd", "bnrt", "crm", "dt" }; // input
    cout << boolalpha << validWordSquare(words)<<endl; // output:true row[0]="abcd"==col[0]="abcd"
    system("pause");
}

bool validWordSquare(vector<string> &words)
{
    int n=words.size();
    for (int i=0;i<n;i++)
    {
        for (int j=0; j<words[i].size(); j++)
        {
            if (words[i][j]!=words[j][i])
                return false;
        }
    }
    return true;
}
