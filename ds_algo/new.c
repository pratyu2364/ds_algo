#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node
{
  int data;
  struct node* next;
}node;
node* createlinkedlist(int m)
{
  node*head =NULL;
  node *p=NULL;
  node *temp=NULL;
  int i;

  for(i=0;i<m;i++)
  {
    temp=(node*)malloc(sizeof(node));
    scanf("%d",&(temp->data));
    temp->next=NULL;

    if(head==NULL)
    {
      head=temp;
    }
    else
    {
      p=head;
      while(p->next!=NULL)
      {
        p=p->next;
      }
      p->next=temp;
    }
  }
  return head;
}
  void displaylinkedlist(node*head)
  {
    node* temp;
    temp=head;
    while(temp->next!=NULL)
    {
      printf("%d-->",temp->data);
      temp=temp->next;
    }
    printf("%d",temp->data);
  }

void insert_sorted(node** head,int num)
{
  node* temp;
  node*p=NULL;
  temp=malloc(sizeof(node));
  temp->next=NULL;
  temp->data=num;
  if(*head=NULL)
  {
  *head=temp;
   p=*head;
 }
 else if(*head!=NULL && (*head->data)>num)
 {
   temp->next=*head;
   *head=temp;

 }
  else
  {
    while(temp->data<num && temp!=NULL)
    {
      p=temp
      temp=temp->next;
    }
    temp->next=p->next;
    p->next=temp;
  }
}
int main()
{
  node*head=NULL;
  head=createlinkedlist(3);
  insert_sorted(&head,5);
  displaylinkedlist(head);



}
