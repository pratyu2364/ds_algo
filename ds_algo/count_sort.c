#include<stdio.h>
#include<string.h>
#include<stdlib.h>
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
int find_max(int a[],int l,int r)
{
  int i,j,k,max=-9999;
  for(i=l;i<=r;i++)
      {
        if(max<a[i])
        max=a[i];
      }
  return max;

}
void countsort(int a[],int n)
{
  int i,j,k,value;
  value=find_max(a,0,n-1);
  int*count=(int*)malloc(sizeof(int)*(1000));
  int*b=(int*)malloc(sizeof(int)*n);
  initiliaze(count,0,value-1);

  for(i=0;i<n;i++)
  {
    ++count[a[i]];
  }
  for(i=1;i<=value;i++)
  count[i]=count[i-1]+count[i];

  for(i=n-1;i>=0;i--)
  {
  b[--count[a[i]]]=a[i];
  }
  //  b[--count[a[0]]]=a[0];
  for(i=0;i<n;i++)
  a[i]=b[i];
}
int main()
{
  int a[20],n,i;
  scanf("%d",&n);
  for(i=0;i<n;i++)
  scanf("%d",&a[i]);
  countsort(a,n);
  for(i=0;i<n;i++)
  {
    printf("%d ",a[i]);
  }

//  printf("%d",a[i]);


}
