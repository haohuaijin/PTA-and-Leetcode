#include <iostream>
using namespace std;
const int MAX = 520;
const int INFO = 100000;
int N,M,S,D;
int G[MAX][MAX]; //长度
int F[MAX][MAX]; //费用
int Dist[MAX]; //最短路径
int Val[MAX]; //花费
int book[MAX];
void Dijkstra(){
    int min,k;
    book[S] = 1;
    while(1){
        min = INFO;
        for(int i=0;i<N;i++){
            if(!book[i] && Dist[i] < min){
                k = i;
                min = Dist[i];
            }
        }
        if(min == INFO) break;
        book[k] = 1;
        for(int i=0;i<N;i++){
            if(!book[i] && G[k][i] + Dist[k] <= Dist[i]){
                if(G[k][i] + Dist[k] < Dist[i]){
                    Dist[i] = G[k][i] + Dist[k];
                    Val[i] =  F[k][i] + Val[k];
                } else {
                    if(F[k][i] + Val[k] < Val[i]){
                        Val[i] = F[k][i] + Val[k];
                    }
                }
            }
        }
    }
}

int main(){
    int V1,V2,Len,Fee;
    scanf("%d%d%d%d",&N,&M,&S,&D);
    for(int i=0;i<N;i++){ //初始化G[][],F[][]
        Dist[i] = INFO;
        Val[i] = INFO;
        for(int j=0;j<N;j++){
            if(i == j){
                G[i][j] = 0;
                F[i][j] = 0;
            } else {
                G[i][j] = INFO;
                F[i][j] = INFO;
            }
        }
    }
    for(int i=0;i<M;i++){ //读入数据，初始化Len,Fee
        scanf("%d%d%d%d",&V1,&V2,&Len,&Fee);
        G[V1][V2] = Len; G[V2][V1] = Len;
        F[V1][V2] = Fee; F[V2][V1] = Fee;
    }
    Dist[S] = 0;
    Val[S] = 0;
    for(int i=0;i<N;i++){ //DijKstra初始化
        if(G[S][i] != INFO){
            Dist[i] = G[S][i];
            Val[i] = F[S][i];
        }
    }
    Dijkstra();
    printf("%d %d\n",Dist[D],Val[D]);
    system("pause");
    return 0;
}