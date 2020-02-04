#include<string.h>
#include<stdio.h>
#include<stdlib.h>
int main()
{
  int count,n;
  int testcase,testcount,i,j,k=0;
  scanf("%d",&testcase);
  int*c=(int*)malloc(sizeof(int)*10000);
  for(testcount=0;i<testcase;testcount++)
  {
    count=0;
    scanf("%d",&n);
    char*s=(char*)malloc(sizeof(int)*n);
    scanf("%s",s);
    for(i=0;i<n-3;i++)
    {
      if(s[i]=='J' && s[i+1]=='G' && s[i+2]=='E' && s[i+3]=='C')
      count++;

    }
    c[k++]=count;
      free(s);
  }
  for(i=0;i<k-1;i++)
  {
    printf("%d\n",c[i]);
  }
  printf("%d",c[k-1]);
  free(c);
}
