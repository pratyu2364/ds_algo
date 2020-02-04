#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
  int n,i,j,k,count=0;
  scanf("%d",&n);
  int*xy=(int*)malloc(sizeof(int*)*2*n);
  for(i=0;i<2*n;i++)
  {
    scanf("%d",&xy[i]);
  }
  for(i=0;i<2*n;i=i+2)
  {
    for(j=i+2;j<2*n;j=j+2)
    {
      if (xy[i]!=xy[i+2] && xy[i+1]!=xy[i+3])
      {
        count++;
      }
    }
  }
  printf("%d",count);
}
