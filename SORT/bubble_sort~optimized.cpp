// 优化的冒泡排序 - 遇到已排好序的进入下一循环
// 时间复杂度：最好：O(n), 最坏：O(n²), 平均：O(n²); 空间复杂度：O(1)
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
    int tmp; bool flag;
    for (int i=n-1; i>0; --i)
    {
        flag=false;
        for (int j=0; j<i; ++j)
        {
            if (arr[j]>arr[j+1])
            {
                tmp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=tmp;
                flag=true;
            }
            if (!flag) break;
        }
    }
}