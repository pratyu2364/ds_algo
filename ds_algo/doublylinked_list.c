#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct node
{
  int data;
  struct node* next;
  struct node* prev;
}node;
void display(node* head)
{
  node*p=head;
  while(p!=NULL)
  {
    printf("%d ",p->data);
    p=p->next;
  }
}

void append_at_begining( node**head,int key)
{
  node* p=*head;
  node*temp=(node*)malloc(sizeof(node));
  temp->data=key;
  temp->next=NULL;
  temp->prev=NULL;
  *head=temp;
  temp->next=p;
  p->prev=temp;

}
void create_linkedlist(node**head,int key)
{
  node* p=*head;
  node*temp=(node*)malloc(sizeof(node));
  temp->data=key;
  temp->next=NULL;
  temp->prev=NULL;
  if(*head==NULL)
  {
    *head=temp;
  //  temp->prev=NULL;
  //  temp->next=NULL;
  }
  else
  {
    while(p->next!=NULL)
    {
    p=p->next;
    }

  p->next=temp;
  temp->prev=p;
  temp->next=NULL;
  printf("DONE\n");
}
}
int main()
{
  node*head=NULL;
  create_linkedlist(&head,1);
  create_linkedlist(&head,2);
  create_linkedlist(&head,3);
  create_linkedlist(&head,14);
  create_linkedlist(&head,12);
  append_at_begining(&head,122);
  display(head);

}
