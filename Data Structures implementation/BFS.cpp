//邻接矩阵储存的图 - BFS
//IsEdge(Graph V,W)检查<V,W>是否图Graph中的一条边，即W是否是W的邻接点
//此函数根据图的不同类型有不同的实现，关键取决于对不存在的边的表示方法
//例如对有权图，如果不存在的边初始化为INFO，则函数如下
bool IsEdge(MGraph Graph,Vertex V,Vertex W){
    return Geaph->G[V][W]<INFO ? true : false;
}

//Visited[]为全局变量，已初始化为false
void BFS(MGraph Graph,Vertex S,void(*Visit)(Vertex)){
    Queue Q;
    Vertex V,W;

    Q = CreateQueue(MaxSize); //创建空的队列，MaxSize为外部定义的常数
    //访问顶点S，按需修改
    Visit(S);
    Visited[S] = true; //标记S已访问
    AddQ(Q,S); //S入队列

    while(!IsEmpty){
        V = DeleteQ(Q);
        for(W=0;W<Graph->Nv;W++){
            if(!Visited[W] && IsEdge[Graph,V,W]){
                Visit(W);
                Visited[W] = true;
                AddQ(Q,W);
            }
        }
    }
}
