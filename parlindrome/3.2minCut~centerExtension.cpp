// ���ٷָ����-������չ��
// s.length��[1,2000]
#include <bits/stdc++.h>
using namespace std;
int minCut(string s);

int main()
{
    string s="cbccccbc"; // ����
    cout<<minCut(s)<<endl; // ���:0
    system("pause");
}

int minCut(string s)
{
    int n=s.length();
    vector<int>f(n+1); // f[i]:s[0,i)����С�ָ����
    for (int i=0;i<=n;i++) // ��ʼ��; f[0]=-1
        f[i]=i-1;
    for (int i=0;i<n;i++) 
    {
        f[i+1]=min(f[i+1],f[i]+1);
        if (i==n-1) break;

        int start=i,end=i+1; // ż����
        while (s[start]==s[end])
        {
            f[end+1]=min(f[end+1],f[start]+1); // ����
            if (start==0 || end==n-1) break;
            --start,++end;
        }

        start=i-1,end=i+1; // ������
        if (start<0) continue;
        while (s[start]==s[end])
        {
            f[end+1]=min(f[end+1],f[start]+1); // ����
            if (start==0 || end==n-1) break;
            --start,++end;
        }
        if (f[n]==0) return 0;
    }
    return f[n];
}