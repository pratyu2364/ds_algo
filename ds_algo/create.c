#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node
{
  int data;
  struct node *next;
}node;
int count(node*head)
{
  int count1=1;
  node* p;
  p=head;
  while(p->next!=NULL)
  {
    p=p->next;
    count1++;
  }
  return count1;
}
void delete(node*head)
{
  node*p=NULL;
  node*temp=NULL;
  int position,i;
  p=head;
  printf("\nENTER THE POSTION THAT U WANT TO DELETE:");
  scanf("%d",&position);
  if(position!=1 )
  {
    for(i=1;i<position-1;i++)
    {
      p=p->next;
    }
    temp=p;
    p=p->next;
    temp->next=p->next;
    p->next=NULL;

  }
}
void insert(node*head)
{
  node*new=(node*)malloc(sizeof(node*));
  new->next=NULL;
  node*temp=NULL;
  node*p=NULL;
  temp=head;
  p=head;
  int i,position;
  printf("\nENTER AN INTEGER THAT U WANT TO APPEND:");
  scanf("%d",&(new->data));
  printf("\nENTER THE POSITION AT WHICH U WANT YOUR DATA:" );
  scanf("%d",&position);
  if(position!=1 && position<=count(head))
  for(i=1;i<position-1;i++)
  {
    p=p->next;
  }
  temp=p->next;
  p->next=new;
  new->next=temp;

}
void append(node* head)
{
  node* new=malloc(sizeof(node));
  new->next=NULL;
  node*temp=NULL;
  node*p=NULL;
  p=head;
  while(p->next!=NULL)
  {
    p=p->next;
  }
  printf("ENTER THE NUMBER THAT U WANT TO APPEND AT LAST:");
  scanf("%d",&(new->data));
  p->next=new;
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
int main()
{
  int n;
  scanf("%d",&n);
  node* HEAD=NULL;
  HEAD=createlinkedlist(n);
  append(HEAD);
  displaylinkedlist(HEAD);
  insert(HEAD);
  displaylinkedlist(HEAD);
  delete(HEAD);
  displaylinkedlist(HEAD);

}
