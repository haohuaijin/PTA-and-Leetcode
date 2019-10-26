#include <stdio.h>
#include <stdlib.h>
typedef struct GNode *Graph;
struct GNode{
    int Nv;
    int Ne;
    int Vertex[11];
    int Edge[11][11];
};
typedef struct Node *QNode;
struct Node{
    int Data;
    QNode Next;
};
typedef struct{
    QNode rear,front;
}*Queue;
int book[11]; //纪录访问的结点
void CreateGraph(Graph G){
    int v1,v2;
    scanf("%d %d",&G->Nv,&G->Ne);
    for(int i=0;i<G->Nv;i++) G->Vertex[i] = i;
    for(int i=0;i<G->Nv;i++)
        for(int j=0;j<G->Nv;j++)
            G->Edge[i][j] = 0;
    for(int i=0;i<G->Ne;i++){
        scanf("%d %d",&v1,&v2);
        G->Edge[v1][v2] = 1;
        G->Edge[v2][v1] = 1;
    }
}
QNode CreateQNode(){
    QNode q = (QNode)malloc(sizeof(struct Node));
    q->Data = -1;
    q->Next = NULL;
    return q;
}
Queue CreateQueue(){
    Queue q = (Queue)malloc(sizeof(Queue));
    q->rear = q->front = NULL;
    return q;
}
void AddQ(Queue Q,int X){
    QNode q = CreateQNode();
    q->Data = X;
    q->Next = NULL;
    if(Q->front == NULL)
        Q->rear = Q->front = q;
    else{
        Q->rear->Next = q; //使q成为最后一个元素
        Q->rear = q; //更新rear
    }
}
int DeleteQ(Queue Q){
    int x;
    if(Q->rear == Q->front){ //分类讨论
        x = Q->front->Data;
        Q->rear = Q->front = NULL;
    } else {
        QNode q = Q->front;
        x = q->Data;
        Q->front = q->Next;
        free(q);
    }
    return x;
}
void DFS(Graph G,int i){
    if(book[i] == 1)
        return;
    else{
        book[i] = 1;
        printf(" %d",i);
        for(int j=0;j<G->Nv;j++)
            if(G->Edge[i][j] == 1) //加不加book[j] == 0
                DFS(G,j);
    }
}
void BFS(Queue Q,Graph G,int i){
    int X;
    AddQ(Q,i);
    book[i] = 1;
    while(Q->front != NULL){
        X = DeleteQ(Q);
        printf(" %d",X);
        for(int j=0;j<G->Nv;j++){
            if(book[j] == 0 && G->Edge[j][X] == 1){
                AddQ(Q,j);
                book[j] = 1;
            }
        }
    }
}
int main(){
    Graph G;
    G = (Graph)malloc(sizeof(struct GNode));
    CreateGraph(G);
    for(int i=0;i<G->Nv;i++){
        if(book[i] == 0){
            printf("{");
            DFS(G,i);
            printf(" }\n");
        }
    }
    for(int i=0;i<G->Nv;i++) book[i] = 0;
    Queue Q = CreateQueue();
    for(int i=0;i<G->Nv;i++){
        if(book[i] == 0){
            printf("{");
            BFS(Q,G,i);
            printf(" }\n");
        }
    }
    system("pause");
    return 0;
}