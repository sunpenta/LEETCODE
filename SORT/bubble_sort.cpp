// 冒泡排序
#include <iostream>
using namespace std;
void bubble_sort(int arr[], int n);

int main()
{

}

void bubble_sort(int arr[], int n)
{
    int tmp;
    for (int i=n-1; i>0; ++i)
    {
        for (int j=0; j<i; ++j)
        {
            if (arr[i+1]>arr[i])
            {
                tmp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=tmp;
            }
        }
    }
}