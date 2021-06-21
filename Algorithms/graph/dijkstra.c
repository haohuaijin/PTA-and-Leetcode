#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

// 返回从start顶点到其他其他未访问顶点的最近距离的顶点号
int findMinDist(Graph *g, int *dist, int *visit){
	int minV;
	int minDist = INFINITE;
	for(int i=0; i < g->nv; ++i){
		if(visit[i] == 0 && dist[i] < minDist){
			minDist = dist[i];
			minV = i;
		}
	}
	if(minDist < INFINITE) //找到最小顶点
		return minV;
	else 
		return -1;
}

// return: 是否可使用dijkstra算法，1:可以，0:不可以。
int dijkstra(Graph *g, int *dist, int*path, int start){
	int visit[g->nv];
	//初始化数据
	for(int i=0; i<g->nv; ++i){
		dist[i] = g->edge[start][i];
		if(dist[i] < INFINITE)
			path[i] = start;
		else
			path[i] = -1;
		visit[i] = 0; //0为没有访问过
	}
	dist[start] = 0;
	visit[start] = 1; 

	while(1){
		int v = findMinDist(g, dist, visit);
		if(v == -1) break;
		visit[v] = 1;
		for(int i = 0; i < g->nv; ++i){
			if(visit[i] == 0 && g->edge[v][i] < INFINITE){
				if(g->edge[v][i] < 0) //有负边
					return 0;
				if(g->edge[v][i] + dist[v] < dist[i]){
					dist[i] = dist[v] + g->edge[v][i];
					path[i] = v;
				}
			}
		}
	}
	return 1;
}

int main(){
	//创建一个测试用例
	Graph *g = CreateGraph(6, 8);
	for(int i=0; i < g->nv; ++i){
		for(int j = 0; j < g->nv; ++j){
			if(i == j){
				g->edge[i][i] = 0;
			} else {
				g->edge[i][j] = INFINITE;
			}
		}
	}
	//初始化边
	g->edge[1][0] = 7;	g->edge[0][1] = 7;
	g->edge[2][0] = 11;	g->edge[0][2] = 11;
	g->edge[2][1] = 10;	g->edge[1][2] = 10;
	g->edge[3][2] = 5;	g->edge[2][3] = 5;
	g->edge[3][1] = 9;	g->edge[1][3] = 9;
	g->edge[5][2] = 8;	g->edge[2][5] = 8;
	g->edge[4][2] = 7;	g->edge[2][4] = 7;
	g->edge[5][4] = 6;	g->edge[4][5] = 6;

	// 运行dijkstra算法
	int dist[g->nv], path[g->nv];
	int right = dijkstra(g, dist, path, 0);

	int pass = 3;
	while(pass != 0){
		printf("%d <- ", pass);
		pass = path[pass];
	}
	printf("%d\n", 0);
	return 0;
}