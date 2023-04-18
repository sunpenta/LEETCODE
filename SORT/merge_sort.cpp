// 归并排序
// 时间复杂度: T(n)=T(n/2)+O(n) O(logn); 空间复杂度:O(logn)
#include <iostream>
using namespace std;
void merge_sort(int arr[], int l, int r);
void print(int arr, int n);
int main()
{

}

void merge(int arr[], int l, int mid, int r)
{
    int copy[r-l+1];
    int i=l, j=mid+1, k=l;
    while (i<mid && j<r)
    {
        
    }
}
void merge_sort(int arr[], int l, int r)
{
   if (l>=r) return;
   int mid=l+(r-l)/2;
   merge_sort(arr, l, mid);
   merge_sort(arr,mid+1, r); 
   merge(arr,l,mid,r);
}
void print(int arr, int n)
{

}