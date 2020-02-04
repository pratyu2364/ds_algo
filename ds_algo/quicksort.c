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
void quicksort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);

        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}
