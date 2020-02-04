#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void merge(int a[],int l,int mid,int h)
{
  int*b=(int*)malloc(sizeof(int)*(h-l+1));
  int i,j,k,n1,n2;
  n1=mid-l+1;
  n2=h-(mid+1)+1;
  i=l;
  j=mid+1;
  k=0;
  while(i<=mid && j<=h)
  {
    if(a[i]<a[j] &&j<=h)
    {
    b[k]=a[i];
    k++;
    i++;
    }
    else if(a[j]<a[i] && i<=mid)
    {
    b[k]=a[j];
    k++;
    j++;
    }
  }
  while(i<=mid)
  {
  b[k]=a[i];
  k++;
  i++;
  }
  while(j<=h)
  {
  b[k]=a[j];
  k++;
  j++;
  }
  for(i=0;i<k;i++)
  {
    a[i+l]=b[i];
  }
  free(b);
}
void print(int a[],int l,int h)
{
  int i;
  for(i=l;i<=h;i++)
  printf("%d ",a[i]);
}
void mergesort(int a[],int l,int h)
{
  int mid;
  if(l<h)
  {
    mid=(l+h)/2;
    mergesort(a,l,mid);
    mergesort(a,mid+1,h);
    merge(a,l,mid,h);
  }
}
int main()
{
  int a[100];
  int i,n;
  scanf("%d",&n );
  for(i=0;i<n;i++)
  {
  scanf("%d",&a[i]);
  }
  mergesort(a,0,n-1);
  //merge(a,0,2,n-1);
  print(a,0,n-1);

}
