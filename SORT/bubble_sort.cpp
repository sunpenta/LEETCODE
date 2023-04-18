// 冒泡排序
#include <iostream>
using namespace std;
void bubble_sort(int arr[], int n);

int main()
{
    int arr[]={3,2,5,7,4}; int n=5;
    bubble_sort(arr, n);
    for (int num:arr)
        cout<<num<<" ";
    return 0;
}

void bubble_sort(int arr[], int n)
{
    // int tmp;
    for (int i=n-1; i>0; ++i)
    {
        for (int j=0; j<i; ++j)
        {
            if (arr[j+1]<arr[j])
            {
                int tmp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=tmp;
            }
        }
    }
}