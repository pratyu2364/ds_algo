#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node
{
  int data;
  struct node* next;
}node;
void print(node*head)
{
  node* p=head;
  while(p!=NULL)
  {
    printf("%d",p->data);
    p=p->next;
  }

}

void create_linkedlist(node**head,int key)
{
  int i,j;
  node*p=*head;
  node*temp=(node*)malloc(sizeof(node));
  temp->data=key;
  temp->next=NULL;
  if(*head==NULL)
  {

    *head=temp;
  }
  else
  {
    while(p->next!=NULL)
    {
      p=p->next;
    }
    p->next=temp;

  }
}
void create_linkedlist_of_n_cir(node*head,int n)
{
  int *key=(int*)malloc(sizeof(int)*n);
  int i,j=0;
  node*p=head;
  for(i=0;i<n;i++)
  {

    scanf("%d",&key[j]);
    create_linkedlist(&head,key[j]);
    j++;

  }
  while(p->next!=NULL)
  {
    p=p->next;
  }
  p->next=head;

}
int floyyd_find_algo(node**head)
{
  node*p1=*head;
  node*p2=*head;
  while(p2!=NULL)
  {
      p1=p1->next;
      p2=p2->next;
      if(p2!=NULL)p2->next;
      else
      return 0;
      if(p1==p2)
      return 1;
  }
  return 0;
}

int main()
{
  node* head=NULL;
  int n,value;
  scanf("%d",&n);
  create_linkedlist_of_n_cir(head,n);
  print(head);
  //value=floyyd_find_algo(&head);
  //printf("%d",value);
}
