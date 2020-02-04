#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"quickSort.h"
int main()
{
  int a[20];
  int i,n;
  for(i=0;i<n;i++)
  {
    scanf("%d",&a[i]);
  }
  quicksort(a,0,n-1);
  for(i=0;i<n;i++)
  {
    printf("%d",a[i]);
  }
}
