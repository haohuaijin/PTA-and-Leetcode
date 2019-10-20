#include <stdio.h>
#include <stdlib.h>
#define MaxVertexNum 100
typedef int Vertex;
typedef int WeightType;
typedef char DataType;

typedef struct ENode *PtrToENode;
struct ENode{ //边的定义
    Vertex V1,V2;
    WeightType Weight;
};
typedef PtrToENode Edge;

typedef struct AdjVNode *PtrToAdjVNode;
struct AdjVNode{ //点的定义
    Vertex AdjV; //邻接点下标
    WeightType Weight; //权重
    PtrToAdjVNode Next; //指向下一个邻接点
};

typedef struct Vnode{ //表头定义
    PtrToAdjVNode FirstEdge; //边表头指针
    DataType Data; //数据
    //多数情况Data没有数据，可以不用
}AdjList[MaxVertexNum];

typedef struct GNode *PtrToGNode;
struct GNode{
    int Nv; //顶点数
    int Ne; //边数
    AdjList G; //邻接表
};
typedef PtrToGNode LGraph; // 以邻接表储存图的类型


LGraph CreateGraph(int VertexNum){
    Vertex V;
    LGraph Graph;

    Graph = (LGraph)malloc(sizeof(struct GNode));
    Graph->Nv = VertexNum;
    Graph->Ne = 0;
    //初始化邻接表头指针
    for(V = 0;V < Graph->Nv;V++)
        Graph->G[V].FirstEdge = NULL;
    return Graph;
}

void InsertEdge(LGraph Graph,Edge E){
    PtrToAdjVNode NewNode;
    //插入边<V1,V2>
    //为V2建立新结点
    NewNode = (PtrToAdjVNode)malloc(sizeof(struct AdjVNode));
    NewNode->AdjV = E->V2;
    NewNode->Weight = E->Weight;
    //将V2插入V1的表头
    NewNode->Next = Graph->G[E->V1].FirstEdge;
    Graph->G[E->V1].FirstEdge = NewNode;

    //若是无向图，还要插入<V2,V1>
    NewNode = (PtrToAdjVNode)malloc(sizeof(struct AdjVNode));
    NewNode->AdjV = E->V1;
    NewNode->Weight = E->Weight;
    //插入
    NewNode->Next = Graph->G[E->V2].FirstEdge;
    Graph->G[E->V2].FirstEdge = NewNode;
}

LGraph BuildGraph(){
    LGraph Graph;
    Edge E;
    Vertex V;
    int Nv,i;

    scanf("%d",&Nv); //读入读入顶点个数
    Graph = CreateGraph(Nv); //建图

    scanf("%d",&(Graph->Ne)); //读入边数
    if(Graph->Ne != 0){ //如果有边
        E = (Edge)malloc(sizeof(struct ENode)); //建立边结点
        for(i = 0;i < Graph->Ne;i++){
            //读入格式为 起点 终点 权重
            scanf("%d %d %d",&E->V1,&E->V2,&E->Weight);
            InsertEdge(Graph,E);
        }
    }

    //如果顶点有数据，则读入数据
    for(V = 0;V < Graph->Nv;V++)
        scanf("%c ",&(Graph->G[V].Data));

    return Graph;
}

int main(){
    printf("Hello,World\n");
    system("pause");
    return 0;
}














