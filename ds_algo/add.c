#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
  int c=0,count=0,s[40];
  int sum=0;
  int l1,l2;
  int i,j,k=0;
  char s1[20],s2[20],s3[40];
  scanf("%s",s1);
  scanf("%s",s2);
  l1=strlen(s1);
  l2=strlen(s2);

  if(l2>l1)
  {
    memset(s1+l2-1,'0',(l2-l1)*sizeof(s1[0]));
  }
  else
  {
    memset(s2+l1-1,'0',(l1-l2)*sizeof(s2[0]));
  }
  strrev(s1);
  strrev(s2);
  for(i=0;i<l2 || i<l1;i++)
  {
    sum=(c+(s1[i]-'0')+(s2[i]-'0'));
    s[k++]=sum%10;
    c=sum/10;
    count++;
  }
  for(i=count;i>=0;i--)
  {
    printf("%d",s[i]);
  }



}
