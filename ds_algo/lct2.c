#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#define SIZE 10
typedef struct node
{
  struct node* next;
  int data;
}node;
int hash(int key)
{
  return key%SIZE;
}
int search_in_linklist(node*head,int key)
{
  node*p=head;
  int val=0;
  while(p!=NULL)
  {
    if(p->data==key)
    {
      val=1;
      break;
    }
    p=p->next;
  }
  return val;


}
int search_in_hash(node*HT[],int key)
{
  int index;
  int value;
  index=hash(key);
  value=search_in_linklist(HT[index],key);
  return value;
}
void insert_in_linkedlist(node**HEAD,int key)
{
  node*p=*HEAD;
  node*temp=malloc(sizeof(node));
  temp->data=key;
  temp->next=NULL;
  if(*HEAD==NULL)
  *HEAD=temp;
  else
  {
  while(p->next!=NULL)
  p=p->next;

  p->next=temp;
  }

}
void insert_in_hash(node* HT[],int key)
{
  int index=hash(key);
  insert_in_linkedlist(&HT[index],key);
}
int main()
{
  node* hashtable[SIZE];
  int i;
  int key;

  insert_in_hash(hashtable,1);
  insert_in_hash(hashtable,3);
  insert_in_hash(hashtable,5);
  insert_in_hash(hashtable,7);
  insert_in_hash(hashtable,6);
  insert_in_hash(hashtable,16);
  insert_in_hash(hashtable,26);
  insert_in_hash(hashtable,36);

  scanf("%d",&key);
  i=search_in_hash(hashtable,key);
  printf("%d",i);




}
