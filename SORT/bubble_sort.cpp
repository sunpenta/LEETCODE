// 冒泡排序
// 时间复杂度：最好：O(n), 最坏：O(n²), 平均：O(n²); 空间复杂度：O(n)
#include <iostream>
using namespace std;
void bubble_sort(int arr[], int n);

int main()
{
    int arr[]={3,2,5,7,4}; int n=5;
    bubble_sort(arr, n);
    for (int num:arr)
        cout<<num<<" ";
    cout<<endl;
    return 0;
}

void bubble_sort(int arr[], int n)
{
    int tmp;
    for (int i=n-1; i>0; --i)
    {
        for (int j=0; j<i; ++j)
        {
            if (arr[j]>arr[j+1])
            {
                tmp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=tmp;
            }
        }
    }
}