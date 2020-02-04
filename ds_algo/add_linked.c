#include<stdio.h>
#include<string.h>
#include<stdlib.h>
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
      temp->data=0;
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
void insert(char*string, node* head)
{
  node* temp=NULL;
  node* p=NULL;
  temp=head;
  int i=strlen(string)-1;

    while(temp!=NULL || i==0)
    {
    temp->data=string[i]-'0';
    temp=temp->next;
    i--;
  }
  }
int compare(int a,int b)
{
  if(a>=b)
  return a;
  else
  return b;
}
void adding(node*h1,node*h2,node*h3)
{
  node* temp1=h1;
  node* temp2=h2;
  node* temp3=h3;
  int c=0,sum=0;
  while(temp1!=NULL || temp2!=NULL)
  {
    sum=(temp1->data)+(temp2->data)+c;
    c=sum/10;
    sum=sum%10;
    temp3->data=sum;
    temp3=temp3->next;
    temp1=temp1->next;
    temp2=temp2->next;

  }

}
void displaylinkedlist(node*head)
{
  node* temp;
  temp=head;
  while(temp!=NULL)
  {
    printf("%d",temp->data);
    temp=temp->next;
  }
}
node* reverse(node*head,int m)
{
  int n,i;

  node* temp1=head;
  node* p=NULL;
  node* head2=NULL;
  head2=createlinkedlist(m);
  node*temp2=head2;
  for(n=m;n>=1;n--)
  {

  for(i=1;i<=n-1;i++)
  {
    temp1=temp1->next;
  }

  if(temp2!=NULL)
  {
  temp2->data=temp1->data;
  temp2=temp2->next;
  temp1=head;
}
}
return head2;
}
int main()
{
  int i,j,k;
  char s1[1000],s2[1000];
  scanf("%s",s1);
  scanf("%s",s2);
  node* head1=NULL;
  node* head2=NULL;
  node*head3=NULL;
  node*head4=NULL;
  int length;
  length=compare(strlen(s1),strlen(s2));
  head1=createlinkedlist(length);
  head2=createlinkedlist(length);
  insert(s1,head1);
  insert(s2,head2);
  head3=createlinkedlist(length);
  adding(head1,head2,head3);
  head4=reverse(head3,length);
  displaylinkedlist(head4);
}
