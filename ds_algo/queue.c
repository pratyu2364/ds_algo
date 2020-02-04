#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct queue
{
  int size;
  int front;
  int rear;
  int* arr;
}queue;
void create(queue *qu,int size)
{

  qu->front=qu->rear=0;
  qu->size=size;
  qu->arr=(int*)malloc(sizeof(int)*size);

}
void enqueue(queue *qu,int x)
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
int dequeue(queue *qu)
{
  int x;
  x=-1;
  if(qu->front==qu->rear)
  printf("queue is empty\n");
  else
  {
    qu->front=(qu->front+1)%(qu->size);
    x=qu->arr[qu->front];

  }
  return x;
}
void display(queue qu)
{
  int i;
  for(i=qu.front+1;i<=(qu.rear);i++)
  {
    printf("%d ",qu.arr[i]);
  }
}

int main()
{
  queue q;
  int size;
  //scanf("%d",&size);
  create(&q,10);
  enqueue(&q,10);
  enqueue(&q,20);
  enqueue(&q,30);
  display(q);
  dequeue(&q);
  display(q);
}
