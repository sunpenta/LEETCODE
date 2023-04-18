// 快速排序 - 分治
// 时间复杂度: T(n)=2*T(n/2)+O(n) O(nlogn); 空间复杂度:O(logn)
#include <iostream>
using namespace std;
void quick_sort(int arr[], int l, int r);
void print(int arr[], int n);

int main()
{
    int arr[]={4,2,3,9,7}; int n=sizeof(arr)/sizeof(arr[0]);
    print(arr,n);
    quick_sort(arr,0,n-1);
    print(arr,n);
    return 0;
}

void swap(int arr[], int i, int j)
{
    int tmp=arr[i];
    arr[i]=arr[j];
    arr[j]=tmp;
}
int partition(int arr[], int l, int r) // -> correct index of pivot
{
    int pivot=arr[r];
    int i=l-1;
    for (int j=0; j<=r-1; ++j) // [l,r-1 | r]
    {
        if (arr[j]<pivot)
        {
            ++i;
            swap(arr,i,j);
        }
    }
    swap(arr,i+1,r);
    return i+1;
}

void quick_sort(int arr[], int l, int r)
{
    int pi=partition(arr,l,r);
    quick_sort(arr,l,pi-1);
    quick_sort(arr,pi+1,r);
}
void print(int arr[], int n)
{
    for (int i=0; i<n; ++i)
        cout<<arr[i]<<" ";
    cout<<endl;
}