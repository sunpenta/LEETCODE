// 归并排序
// 时间复杂度: T(n)=2*T(n/2)+O(n) O(nlogn); 空间复杂度:O(n)
#include <iostream>
using namespace std;
void merge_sort(int arr[], int l, int r);
void print(int arr[], int n);
int main()
{
    int arr[]={9,8,6,7,2,1}; int n=sizeof(arr)/sizeof(arr[0]);
    print(arr,n);
    merge_sort(arr,0,n-1);
    print(arr,n);
}

void merge(int arr[], int l, int mid, int r) // [l,mid] [mid+1,r]
{
    int copy[r-l+1];
    int i=l, j=mid+1, k=0; // note: k begin in 0
    while (i<=mid && j<=r)
    {
        if (arr[i]<arr[j])
            copy[k++]=arr[i++];
        else
            copy[k++]=arr[j++];
    }
    while (i<=mid)
        copy[k++]=arr[i++];
    while (j<=r)
        copy[k++]=arr[j++];
    for (int i=l; i<=r; ++i) // copy[]->arr[]; i∈[l,r]
        arr[i]=copy[i-l]; // note: arr[i] copy[i-l]
}
void merge_sort(int arr[], int l, int r)
{
   if (l>=r) return;
   int mid=l+(r-l)/2;
   merge_sort(arr, l, mid); // T(n/2)
   merge_sort(arr,mid+1, r); // T(n/2)
   merge(arr,l,mid,r); // O(n)
}
void print(int arr[], int n)
{
    for (int i=0; i<n; ++i)
        cout<<arr[i]<<" ";
    cout<<endl;
}