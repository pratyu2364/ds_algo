#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void print_array(int a[],int l,int r)
{
  int i;
  for(i=l;i<=r;i++)
  {
    printf("%d",a[i]);
  }
}
void swap(int*c,int*b)
{
  int temp;
  temp=*c;
  *c=*b;
  *b=temp;
}
int partition(int a[],int l,int r)
{
  int p,i,j,temp;
  i=l;
  j=r;
  if(i<=j)
  {
  p=rand()%(j-i+1)+i;
  swap(&a[p],&a[l]);


  //print(a,l,r);
  //print_array(a,l,r);

  while(i<j)
  {
   while(i<=j && a[i]<=a[l])i++;
   while(i<=j && a[j]>a[l])j--;

   if(i<j)
   {
      swap(&a[i],&a[j]);
      i++;
      j--;
    //  print(a,l,r);
   }
  }
}
  swap(&a[l],&a[j]);
// print_array(a,l,r);

 return j;


}
int findrank(int a[],int l,int r,int rank)
{
  int p,k;
  if(l<=r)
  {
     k=partition(a,l,r);
     if(rank==r-k+1)
         return a[k];
     else if(rank<r-k+1)
         findrank(a,k+1,r,rank);
    else
         findrank(a,l,k-1,rank-r+k-1);
  }
  else
  return -1;
}
int main()
{
  int n;
  int p;
  int a[20];
  int i,rank;
  scanf("%d",&n);
  for(i=0;i<n;i++)
  {
    scanf("%d",&a[i]);
  }
 scanf("%d",&rank);
//  p=partition(a,0,n-1);
  p=findrank(a,0,n-1,rank);
  printf("%d",p);

}
