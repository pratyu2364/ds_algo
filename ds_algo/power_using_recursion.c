#include<string.h>
#include<stdio.h>
#include<stdlib.h>
int power(int x,int n)
{
  static int y;
  if(n==0)
  return 1;
    if(n%2==1)
    {
      y=x*power(x*x,n/2);
      printf("%d %d\n",x,n);
      return y;
    }
    else
    {
    power(x*x,n/2);
    printf("%d %d\n",x,n);
    }
}
int main()
{
  int value;
  value=power(3,6);
  printf("%d",value);
}
