#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void print(int a[],int l,int r)
{
  int i;
  for(i=l;i<=r;i++)
  printf("%d ",a[i]);
}
void initiliaze(int a[],int l,int r)
{
  int i;
  for(i=l;i<=r;i++)
  {
    a[i]=0;
  }
}
void radixsort(int a[],int n,int digit)
{
  int i,j,k=1,value;
  int*b=(int*)malloc(sizeof(int)*(r-l+1));
  int*count=(int*)malloc(sizeof(int)*10000);
  u=power(10,digit);
  for(k=1;k<pow(10);k=k*10)
  {
  initiliaze(count,0,n-1);
    for(i=0;i<n;i++)
      ++count[(a[i]/k)%10];
  for(i=1;i<=9;i++)
  count[i]=count[i-1]+count[i];
  for(i=n-1;i>=0;i--)
  {
  b[--count[(a[i]]/k)%10]=a[i];
  }
  //  b[--count[a[0]]]=a[0];
  for(i=0;i<n;i++)
  a[i]=b[i];
 }
}
