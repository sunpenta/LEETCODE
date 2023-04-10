// 螺旋矩阵III-simulation  l-885
// [rowStart,colStart]->顺时针螺旋->reach all
#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart);

int main()
{
    int rows=5, cols=6, rStart=1, cStart=4; // input
    vector<vector<int>> path=spiralMatrixIII(rows,cols,rStart,cStart); // output
    for (auto row:path)
        cout<<"("<<row[0]<<", "<<row[1]<<")"<<endl;
    system("pause");
}

vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart)
{
    vector<vector<int>> path;
    path.push_back({rStart,cStart});
    int dx=0, dy=1, tmp;
    for (int n=0; path.size()<rows*cols-1; n++)
    {
        for (int i=0; i<n/2+1; i++)
        {
            rStart+=dx; cStart+=dy;
            if (rStart>=0 && rStart<rows && cStart>=0 && cStart<cols)
                path.push_back({rStart,cStart});
        }
        tmp=dx, dx=dy, dy=-tmp; // turn right:[]
    }
    return path;
}
