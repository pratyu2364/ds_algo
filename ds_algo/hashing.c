//open chain hashing
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 10
typedef struct node
{
  int data;
  struct node *next;
}node;
int hash(int key)
{
  return key%SIZE;
}
void Sortedinsert(node**head,int key)
{
  node *p,*q;
  node* temp=NULL;
  temp=(node*)malloc(sizeof(node));
  temp->next=NULL;
  if(*head==NULL)
    *head=temp;
  else
  {
    p=*head;
    while(p!=NULL && p->data<key)
    {
      q=p;
      p=p->next;
    }
    if(p=*head)
    {
       temp->next=*head;
       *head=temp;
    }
    else
    {
      temp->next=q->next;
      q->next=temp;
    }
  }
}
node *search(node**head,int x)
{
  node*p=*head;
  while(p->data!=x)
  {
    p=p->next;
  }
  return p;
}
void insert(node*HT[],int key)
{

  int index;
  index=hash(key);
  Sortedinsert(&HT[index],key);

}
int main()
{
  node* temp;
  int i;
  node* hashtable[SIZE];
  for(i=0;i<SIZE;i++)
  {
    hashtable[i]=NULL;
  }
  insert(hashtable,21);
  insert(hashtable,22);
  insert(hashtable,34);
  temp=search(&hashtable[hash(21)],21);
  printf("%d",temp->data);


}
