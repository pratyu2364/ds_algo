#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
int binarysearch(int a[], int low,int k, int high)
{
  int i,j,mid;
  mid=(low+high)/2;

  if(low<high)
  {
    if(a[mid]==k)
    return 1;
    else if(a[mid]<k)
     binarysearch(a,mid+1,k,high);
    else
    binarysearch(a,low,k,mid);
  }
  return -1;
}
int partition (int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high- 1; j++)
    {

        if (arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
int sum_is_x(int a[],int n,int x)//a[i]+a[j]==x is possible or not; j= x-a[i] am diterate aloop to find the valuue of it
{
  int count=0;
  int i,j;
  quickSort(a,0,n-1);
  for(i=0;i<n;i++)
  {
    j=binarysearch(a,0,x-a[i],n-1);
    if(j==1)
    {
      count++;
  }
 }
  return count;
}
int main()
{
  int x,i,k,n;
  scanf("%d",&n);
  int a[n];
  for(i=0;i<n;i++)
  {
    scanf("%d",&a[i]);
  }
  scanf("%d",&k);
  //quickSort(a,0,n-1);
  for(i=0;i<n;i++)
  printf("%d ",a[i]);
  x=sum_is_x(a,n,k);
  printf("\n%d",x);

}
