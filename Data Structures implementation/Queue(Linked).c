#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
struct Node{
    ElementType Data;
    struct Node *Next;
};
struct QNode{ //链队列结构
    struct Node *front; //指向队头结点,出队
    struct Node *rear; //指向队尾结点,入队
};
typedef struct QNode *Queue;
//操作
Queue CreateQueue(); //建立空的队
void AddQ(Queue q,ElementType item); //入队
ElementType DeleteQ(Queue q); //出队


int main()
{
    Queue q;
    q = CreateQueue();
    AddQ(q,5);
    AddQ(q,15);
    AddQ(q,25);
    DeleteQ(q);
    printf("%d\n",DeleteQ(q));
    return 0;
}

//建立空的队
Queue CreateQueue(){
    Queue q = (Queue)malloc(sizeof(struct QNode));
    q->front = (struct Node*)malloc(sizeof(struct Node));
    q->rear = (struct Node*)malloc(sizeof(struct Node));
    q->front = q->rear = NULL;
    return q;
}

//入队
void AddQ(Queue q,ElementType item){
    struct Node *LastNode;
    LastNode = (struct Node*)malloc(sizeof(struct Node));
    LastNode->Data = item;
    LastNode->Next = NULL; //最后一个元素指向NULL
    if(q->front == NULL){ //若队列是空的
        q->front = q->rear = LastNode;
    } else{
        q->rear->Next = LastNode; //前一个元素指向最后一个
        q->rear = LastNode; //更新rear
    }
}

//出队
ElementType DeleteQ(Queue q){
    ElementType out; //返回的数据
    if(q->front == NULL){//如果队列为空
        printf("队空\n"); return NULL;
    } else if(q->front == q->rear){//如果队列只有一个元素
        out = q->front->Data;
        q->front = q->rear = NULL;
        return out;
    } else {
        struct Node *FirstNode;
        FirstNode = q->front;
        q->front = FirstNode->Next;
        out = FirstNode->Data;
        free(FirstNode);
        return out;
    }
}























