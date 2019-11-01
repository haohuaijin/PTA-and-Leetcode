#include <iostream>
#include <cmath>
using namespace std;
int Nv; //顶点数
int X[101],Y[101]; //顶点坐标
int Dist; //跳的最远距离
int G[101][101]; //是否有边
int book[101]; //是否访问
int flag = 0;
int Flee[101]; //是否可以逃跑
const int INFO = 100000;
void DFS(int i){
    book[i] = 1;
    if(Flee[i] == 1) flag = 1;
    for(int j = 0;j <= Nv;j++){ //注意一共Nv+1个点
        if(!book[j] && G[i][j] == 1){
            DFS(j);
        }
    }
}
int main(){
    int x,y;
    X[0] = Y[0] = 50;
    scanf("%d%d",&Nv,&Dist);
    for(int i = 1;i <= Nv;i++){
        scanf("%d%d",&x,&y);
        X[i] = x + 50;
        Y[i] = y + 50;
        if(pow(Y[i],2) <= pow(Dist,2) || pow(X[i],2) <= pow(Dist,2)||\
            pow(100-Y[i],2) <= pow(Dist,2) || pow(100-X[i],2) <= pow(Dist,2))
            Flee[i] = 1;
    }
    for(int i = 0;i <= Nv;i++){
        for(int j = 0;j <= Nv;j++){
            if(i == j) G[i][j] = 0;
            else G[i][j] = INFO;
            if(pow(X[i]-X[j],2) + pow(Y[i]-Y[j],2) <= pow(Dist,2)){
                G[i][j] = 1;
                G[j][i] = 1;
            }
        }
    }
    for(int j = 0;j <= Nv;j++){ //中间有一个直径15的陆地
        if(pow(X[0]-X[j],2) + pow(Y[0]-Y[j],2) <= pow(Dist+7.5,2)){
            G[0][j] = 1;
            G[j][0] = 1;
        }
    }
    DFS(0);
    if(flag) printf("Yes\n");
    else printf("No\n");
    system("pause");
    return 0;
}