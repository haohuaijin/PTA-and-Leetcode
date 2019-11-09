#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_SIZE 3

typedef int ElementType;
typedef struct QNode *Queue;
struct QNode{
    ElementType Data[MAX_SIZE];
    int front; //指向队首的前一个元素
    int rear; //指向队尾元素
};

/**
 * 循环队列
 */

//操作:建立空队列,是否已满,入队,是否为空,出队
Queue CreateQueue(); //建立空队列
bool IsFull(Queue q); //是否已满
void AddQ(Queue q,ElementType item); //入队
bool IsEmpty(Queue q); //是否为空
ElementType DeleteQ(Queue q); //出队

int main()
{
    Queue q;
    q = CreateQueue();
    AddQ(q,5);
    DeleteQ(q);
    AddQ(q,10);
    AddQ(q,5);
    printf("%d\n",DeleteQ(q));
    return 0;
}

//建立空队列
Queue CreateQueue(){
    Queue q;
    q = (Queue)malloc(sizeof(struct QNode));
    q->front = 0;
    q->rear = 0;
    return q;
}

//判断是否为满
bool IsFull(Queue q){
    //取模是为了避免rear到队尾的特殊情况
    return ((q->rear+1)%MAX_SIZE == q->front);
}

//入队
void AddQ(Queue q,ElementType item){
    if(IsFull(q)){
        printf("队满\n"); return;
    } else {
        //取模实现循环队列
        q->rear = (q->rear+1)%MAX_SIZE;
        q->Data[q->rear] = item;
    }
}

//是否为空
bool IsEmpty(Queue q){
    return (q->front == q->rear);
}

//出队
ElementType DeleteQ(Queue q){
    ElementType out;
    if(IsEmpty(q)){
        printf("空队\n"); return NULL;
    } else {
        //取模实现循环队列
        q->front = (q->front+1)%MAX_SIZE;
        out = q->Data[q->front];
        return out;
    }
}

































