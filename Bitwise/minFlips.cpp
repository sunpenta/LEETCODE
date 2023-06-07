// 使 a | b = c 的最少翻转次数
#include <iostream>
using namespace std;
int minFlips(int a, int b, int c);


int main()
{
    int a=2, b=4, c=7; // input
    int flip=minFlips(a,b,c); // output
    cout<<flip<<endl;
    return 0;
}

int minFlips(int a, int b, int c)
{
    int flip=0;
    for (int i=0; i<31; i++)
    {
        if ((a>>i & 1) | (b>>i & 1) ^ (c>>i & 1))
        {
            if (c>>i & 1)
                flip++;
            else
            {
                if (a>>i & 1)
                    flip++;
                if (b>>i & 1)
                    flip++;
            }
        }
    }
    return flip;
}