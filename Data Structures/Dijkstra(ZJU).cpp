//  邻接矩阵 - 有权图 - Dijkstra
Vertex FindMinDist(MGraph Graph,int Dist[],int collected[]){
    //返回未收录顶点Dist最小者
    Vertex MinV,V;
    int MinDist = INFO;
    for(V = 0;V < Graph->Nv; V++){
        if(collected[V] == false && Dist[V] < MinDist){
            MinDist = Dist[V]; //更新距离
            MinV = V; //更新顶点
        }
    }
    if(MinDist < INFO) //找到最小顶点
        return MinDist;
    else return ERROR;
}
bool Dijkstra(MGraph Graph,int dist[],int path[],Vertex S){
    int collected[MaxVertexNum];
    Vertex V,W;
    //初始化：数据
    for(V = 0;V < Graph->Nv;V++){
        dist[V] = Graph->G[S][V];
        if(dist[V] < INFO)
            path[V] = S;
        else 
            path[V] = -1;
        collected[V] = false;  
    }
    dist[S] = 0;
    collected[S] = true;

    while(1){
        V = FindMinDist(Graph,dist,collected);
        if(V == ERROR) break;
        collected[V] = true;
        for(W = 0;W < Graph->Nv;W++){
            if(collected[W] == false && Graph->G[V][W] < INFO){
                if(Graph->G[V][W] < 0) //有负边 
                    return false;
                if(Graph->G[V][W] + dist[V] < dist[W]){
                    dist[W] = dist[V] + Graph->G[V][W];
                    path[W] = V;
                }
            }
        }
    }
    return true;
}