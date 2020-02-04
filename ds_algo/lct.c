#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#define SIZE 20
 typedef struct node
 {
   int data;
   struct node *next;
 }node;
 void insert_in_linkedlist(node**head,int x)
 {
   node*p=*head;
   node* temp=(node*)malloc(sizeof(node));
   temp->data=x;
   temp->next=NULL;
   if(*head=NULL)
   *head=temp;
   else
   {
     while(p->next!=NULL)
       p=p->next;
     p->next=temp;
   }
 }
 int convert(char v)
 {
   int s;
   s=v-48;
   return s;
 }
 int hash(int key)
 {
   return key%SIZE;
 }
 void insert_in_hashtable(node*HT[],int key)
 {

   int index;
   index=hash(key);
   insert_in_linkedlist(&HT[index],key);
}

 int search(node**head,int x)
 {
   node*p=*head;
   while(p!=NULL)
   {
     if(p->data==x)
       return 1;
     p=p->next;
   }
   return 0;

}

int substring(char*t1,char*t2,int l)
{
  node* head=NULL;
  int k;
  int m,i,j,p,q;
  int n,d;
  int l1,l2;
  node* HT[SIZE];
  for(i=0;i<SIZE;i++)
  {
  HT[i]=NULL;
  }
  l1=strlen(t1);
  l2=strlen(t2);
  p=0;
  q=0;
  d=1;
  for(i=0;i<=l-1;i++)
  d=d*2;
  for(i=0;i<l;i++)
  {
    p=p*2+convert(t1[i]);

  }
  for(j=0;j<l;j++)
  {
    q=2*q+convert(t2[j]);
  }
  insert_in_hashtable(HT,p);
  for(i=1;i<=l1-l;i++)
  {
      p=(p*2-d*convert(t1[i-1])+convert(t1[i+l-1]));
      insert_in_hashtable(HT,p);

}
head=HT[hash(q)];
for(j=1;j<=l2-l;j++)
{


  head=HT[hash(q)];
  if(search(&head,q)==1)
  {
   return 1;
 }

   else
   {
   q=(2*q-d*convert(t2[j-1]))+convert(t2[j+l-1]);
   continue;
   }
}
 return 0;
}
int main()
{
  int l;
  int v;
  char s1[20],s2[20];
  scanf("%s %s %d",s1,s2,&l);
  v=substring(s1,s2,l);
  printf("%d",v);


}
