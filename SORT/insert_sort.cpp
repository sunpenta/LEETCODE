// 插入排序
// 时间复杂度：最好：O(n) 最坏：O(n²) 平均：O(n²); 空间复杂度：O(1); 稳定排序
#include <iostream>
using namespace std;
void insert_sort(int arr[], int n);

int main()
{
    int arr[]={3,2,5,7,4}; int n=5;
    insert_sort(arr, n);
    for (int num:arr)
        cout<<num<<" ";
    cout<<endl;
    return 0;
}
void insert_sort(int arr[], int n)
{
    for (int i=1; i<n; ++i)
    {
        int tmp=arr[i], j;
        for (j=i; j>0 && arr[j-1]>tmp; --j)
            arr[j]=arr[j-1];
        arr[j]=tmp;
    }
}