#include <iostream>
using namespace std;
const int MAX = 100;
const int INFO = 100000;
struct Graph{
    int Nv;
    int Ne;
    int G[MAX][MAX];
    int Data[MAX];
};
int book[MAX]; //标记是否被访问过
int Dist[MAX]; //记录距离
int Path[MAX]; //记录路径
//对于有权图，用邻接矩阵存储
void Dijkstra(int first,Graph &G){
    int k; //储存每次找到的最小节点
    for(int i=0;i<G->Nv;i++){
        Path[i] = -1;
        Dist[i] = INFO;
    }
    //初始化Dist
    for(int i=0;i<G->Nv;i++){
        if(G->G[first][i] != INFO){
            Dist[i] = G->G[first][i]; 
            Path[i] = first;
        }
    }
    Dist[first] = 0;
    book[first] = 1; //标记访问
    while(1){
        min = INFO;
        for(int i=0;i<G->Nv;i++){
            if(!book[i] && Dist[i] < min){
                k = i;
                min = Dist[i];
            }
        }
        if(min == INFO) break;
        book[k] = 1;
        for(int i=0;i<G->Nv;i++){
            if(!book[i] && (Dist[k] + G->G[k][i] < Dist[i])){
                Dist[i] = Dist[k] + G->G[k][i];
                Path[i] = k;
            }
        }
    }
}
int main(){
    
    system("pause");
    return 0;
}