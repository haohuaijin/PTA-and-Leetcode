#ifndef GRAPH_H
#define GRAPH_H

//邻接矩阵表示法
typedef struct Graph{
	int nv; //顶点个数
	int ne; //边的个数
	int *vex; //顶点数据
	int **edge; //边的数据
}Graph;

Graph *CreateGraph(int Nv, int Ne){
	Graph *g = (Graph*)malloc(sizeof(Graph));
	g->nv = Nv;
	g->ne = Ne;
	g->vex = (int*)malloc(sizeof(int)*Nv);
	g->edge = (int**)malloc(sizeof(int*)*Nv);
	for(int i=0; i<Nv; ++i)
		g->edge[i] = (int*)malloc(sizeof(int)*Nv);
	return g;
}

void DeleteGraph(Graph* g){
	free(g->vex);
	for(int i=0; i<g->nv; ++i)
		free(g->edge[i]);
	free(g->edge);
}

#endif