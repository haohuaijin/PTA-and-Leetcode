// 邻接矩阵存储 - Prim最小生成树算法

Vertex FinMinDist(MGraph Graph,WeightType Dist[]){
    //返回未收录顶点dist最小者
    Vertex MinV,V;
    WeightType MinDist = INFO;
    for(V = 0; V < Graph->Nv; V++){
        if(dist[V] != 0 && dist[V] < MinDist){
            // 若V未被收录，且dist[V]更小
            MinDist = dist[V];
            MinV = V;
        }
    }
    if(MinDist < INFO) //找到了
        return MinV;
    else return ERROR;
}


int Prim(MGraph Graph,LGraph MST){
    //将最小生成树保存为邻接表的图MST，返回最小权重和
    WeightType dist[MaxVertexNum],TotalWeight;
    Vertex parenet[MaxVertexNum],V,W;
    int VCount;
    Edge E;

    //初始化。默认初始点下表是0
    for(V = 0; V < Graph->Nv; V++){
        //假设若V到W没有直接的边，则Graph->G[V][W]定义为INFO
        dist[V] = Graph->G[0][V];
        parenet[V] = 0; //暂时定义所有点的初始结点都为0
    }
    TotalWeight = 0; //初始化权重和
    Vcount = 0; //初始化被收录的顶点数
    //创建包含所有顶点，但没有边的图，邻接表
    MST = CreateGraph(Graph->Nv);
    E = (Edge)malloc(sizeof(struct ENode)); //建立空的结点

    //将初始点0收录进MST
    dist[0] = 0;
    VCount++;
    parenet[0] = -1; //当前树根是0

    while(1){
        V = FindMinDist(Graph,dist); //找到最小者
        if(V == ERROR)
            break;
        
        //将V及相应的边 <parenet[V],V> 收录进MST
        E->V1 = parenet[V];
        E->V2 = V;
        E->Weight = dist[V];
        InsertEdge(MST, E);
        TotalWeight += dist[V];
        dist[V] = 0;
        VCount++;

        for(W = 0;W < Graph->Nv; W++){
            if(dist[W] != 0 && Graph->G[V][W] < INFO){
                //若W是V的邻接点并且未被收录
                if(Graph->G[V][W] < dist[W]){
                    //若收录使dist[W]变小
                    dist[W] = Graph->G[V][W]; //更新dist[W]
                    parenet[W] = V;
                }
            }
        }
    } 
    if(VCount < Graph->Nv) //收录的顶点不到|V|个
        TotalWeight = ERROR;
    return TotalWeight;
}
