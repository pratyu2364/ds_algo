#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int convert(char v)
{
  int s;
  s=v-48;
  return s;
}
void check(char*subs,char*s)
{
  int m,i,j,p,q;
  int n,d;
  m=strlen(subs);
  n=strlen(s);
  p=0;
  q=0;
  d=1;
  for(i=0;i<m-1;i++)
  d=d*2;
  for(i=0;i<m;i++)
  {
    p=p*2+convert(s[i]);
  }
  for(j=0;j<m;j++)
  {
    q=2*q+convert(subs[j]);
  }
  for(i=0;i<=n-m;i++)
  {
    if(p==q)
    printf("String found at index %d",i);
    if(i<n-m)
      p=2*(p-d*convert(s[i]))+convert(s[i+m]);
      printf("%d %d\n",q,p);

  }
}
  int main()
  {
    char t[20];
    char sub[20];
    scanf("%s",t);
    scanf("%s",sub);
    check(sub,t);
  }
