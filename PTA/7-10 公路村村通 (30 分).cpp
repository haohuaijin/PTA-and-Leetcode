#include <iostream>
#include <algorithm>
using namespace std;
const int MAX = 1010;
const int INF = 1000000;
int N,M,dist[MAX],Edge[MAX][MAX];
bool book[MAX];
void Prim(){
    int k,count = 0,weight = 0;
    book[1] = true;
    count++;
    for(int i = 1;i <= N;i++) //初始化距离
        dist[i] = Edge[1][i];
    while(count < N){ //加入N-1个点
        int MIN = INF;
        for(int i = 1;i <= N;i++){
            if(!book[i] && MIN > dist[i]){
                k = i;
                MIN = dist[i];
            }
        }
        if(MIN == INF) break;
        book[k] = true;
        count++;
        weight += dist[k];
        for(int i = 1;i <= N;i++){ //更新到生成树的距离
            if(!book[i] && dist[i] > Edge[k][i])
                dist[i] = Edge[k][i];
        }
    }
    if(count >= N) printf("%d\n",weight);
    else printf("-1\n");
}
int main(){
    int V1,V2,W;
    fill(dist+1,dist+N+1,INF);
    fill(book+1,book+N+1,false);
    scanf("%d%d",&N,&M);
    for(int i = 1;i <= N;i++){ //失误,在没有输入N的时候就初始化
        for(int j = 1;j <= N;j++){
            if(i == j) 
                Edge[i][j] = 0;
            else 
                Edge[i][j] = INF;
        }
    }
    for(int i=0;i<M;i++){
        scanf("%d%d%d",&V1,&V2,&W);
        Edge[V1][V2] = W; //顶点从1开始编号
        Edge[V2][V1] = W;
    }
    Prim();
    system("pause");
    return 0;
}