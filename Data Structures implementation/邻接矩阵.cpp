#include <stdio.h>
#include <stdlib.h>
#define MaxVertexNum 100
#define INFINITY 65535 //无符号整数最大值
typedef int Vertex; //结点
typedef int WeightType; //权重
typedef char DataType; //数据
typedef struct ENode *PtrToENode;
struct ENode{ //边的定义
    Vertex V1,V2; //有向图<v1,v2>
    WeightType Weight; //权重
};
typedef PtrToENode Edge;

typedef struct GNode *PtrToGNode; //图结点的定义
struct GNode{
    int Nv; //顶点数
    int Ne; //边数
    WeightType G[MaxVertexNum][MaxVertexNum]; //邻接矩阵
    DataType Data[MaxVertexNum]; //顶点数据
    //多数情况Data[]，没有数据，可以不用
}; 
typedef PtrToGNode MGraph; //以邻接矩阵储存图的类型

MGraph CreateGraph(int VertexNum){
    //初始化y有VertexNum个节点，没边的图
    Vertex V,W;
    MGraph Graph;
    Graph = (MGraph)malloc(sizeof(struct GNode));
    Graph->Nv = VertexNum;
    Graph->Ne = 0;
    for(V = 0;V < Graph.Nv;V++) //默认编号从零开始
        for(W = 0;W < Graph.Ne;W++)
            Graph->G[V][W] = INFINITY;
    return Graph;
}
Void InsertEdge(MGraph Graph,Edge e){
    //插入边<V1,V2>
    Graph->G[e->V1][e->V2] = e->Weight;
    //如果是无向图，还要插入<V2,V1>
    Graph->G[e->V2][e->V1] = E->Weight;
    Graph->Ne++;
}
MGraph BuildGraph(){
    MGraph Graph;
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
        scanf("%c ",&(Graph->Data[V]));

    return Graph;
}















int main(){

    return 0;
}