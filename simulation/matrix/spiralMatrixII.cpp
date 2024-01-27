// 螺旋矩阵II - l-59
// 时间复杂度O(n^2), 空间复杂度：O(n^2)
#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> generateMatrix(int n);

int main()
{
    int n=3; // input
    vector<vector<int>> res=generateMatrix(n);
    for (auto a:res)
    {
        for (int num:a)
            cout << num <<" ";
        cout << endl;
    }
    return 0;
}
vector<vector<int>> generateMatrix(int n)
{
    vector<vector<int>> res(n,vector<int>(n));
    int l=0, r=n-1, u=0, d=n-1, num=1;;
    while (u<=d && l<=r)
    {
        for (int i=l; i<=r; i++)
            res[u][i]=num++;
        u++;
        for (int i=u; i<=d; i++)
            res[i][r]=num++;
        r--;
        for (int i=r; i>=l; i--)
            res[d][i]=num++;
        d--;
        for (int i=d; i>=u; i--)
            res[i][l]=num++;
        l++;
    }
    return res;
}