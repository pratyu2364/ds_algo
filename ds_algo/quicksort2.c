#include<string.h>
#include<stdio.h>
#include<stdlib.h>
void print(int a[],int l,int h)
{
  int i;
  for(i=l;i<=h;i++)
  {
  printf("%d ",a[i]);
  }
}
void swap(int*a,int*b)
{
  int temp;
  temp=*a;
  *a=*b;
  *b=temp;
}
int partition(int a[],int l,int r)
{
  int i,j;
//  int pivot_index=rand()%(r-l+1)+l;
//  swap(&a[pivot_index],&a[l])
  i=l+1;
  j=r;
  while(i<j)
  {
    while(i<=j && a[i]<a[l])i++;
    while(i<=j && a[j]>a[l])j--;

  if(i<j)
  {
      swap(&a[i],&a[j]);
      i++;
      j--;
  }
  }
  swap(&a[l],&a[j]);
  print(a,l,h);
  return j;

}
void quicksort(int a[],int l,int r)
{
  int key;
  int pivot_index;
  if(r>l)
  {
    key=rand()%(r-l+1)+l;
    swap(&a[key],&a[l]);
    pivot_index=partition(a,l,r);
    quicksort(a,l,pivot_index-1);
    quicksort(a,pivot_index+1,r);
  }

}
int main()
{
  int key;
  int a[100];
  int i,n;
  scanf("%d",&n);
  for(i=0;i<n;i++)
   {
     scanf("%d",&a[i]);
   }

   key=partition(a,0,n-1,a[2]);
  // quicksort(a,0,n-1);
  printf("%d\n",key);
//print(a,0,n-1);
}
