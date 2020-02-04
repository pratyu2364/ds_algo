#include<stdio.h>
#include<stdlib.h>
  int power( int x, int n)
{
 int y=1;
  while(n>0)
  {
    if(n%2==1)
    {
      y=y*x;

    }  x=x*x;
      n=n/2;

  }
  return y;
}
int main()
{
  int x,n;
  int sum1;
  scanf("%d %d",&x,&n );
  sum1=power(x,n);
  printf("%d",sum1);
}
