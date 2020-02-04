#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node
{
  int data;
  struct node* rightchild;
  struct node* leftchild;
}node;
node* root=NULL;

typedef struct queue
{
  int size;
  int front;
  int rear;
  node **arr;
}queue;
int isempty(queue qu)
{
  return qu.rear=qu.front;
}
void create(queue *qu,int size)
{

  qu->front=qu->rear=0;
  qu->size=size;
  qu->arr=(node**)malloc(sizeof(node*));

}
void enqueue(queue *qu,node* x)
{
  if(qu->rear==qu->size-1)
  {
    printf("no more space left");
  }
  else
  {
    qu->rear=(qu->rear+1)%qu->size;
    qu->arr[qu->rear]=x;
  }
}
node* dequeue(queue *qu)
{
  node* x;
  if(qu->front==qu->rear)
  printf("queue is empty\n");
  else
  {
    qu->front=(qu->front+1)%(qu->size);
    x=qu->arr[qu->front];

  }
  return x;
}
void createtree()
{
  int x;
  node *p,*t;
  queue q;
  create(&q,20);
  printf("ENTER DATA FOR ROOT:");
  scanf("%d",&x);
  root=(node*)malloc(sizeof(node));
  root->data=x;
  root->rightchild=root->leftchild=NULL;
  enqueue(&q,root);
  while(!isempty(q))
  {
    p=dequeue(&q);
    printf("ENTER LEFT CHILD of %d:",p->data);
    scanf("%d",&x);
    if(x!=-1)
    {
      t=(node*)malloc(sizeof(node));
      t->data=x;
      t->leftchild=t->rightchild=NULL;
      p->leftchild=t;
      enqueue(&q,t);

    }
    printf("ENTER RIGHT CHILD of %d:",p->data);
    scanf("%d",&x);
    if(x!=-1)
    {
      t=(node*)malloc(sizeof(node));
      t->data=x;
      t->leftchild=t->rightchild=NULL;
      p->rightchild=t;
      enqueue(&q,t);
    }
  }
}
  void preorder(node* t)
  {
    if(t!=NULL)
    {
      printf("%d\n",t->data );
      preorder(t->leftchild);
      preorder(t->rightchild);
    }
  }

int main()
{
  createtree();
  preorder(root);

}
