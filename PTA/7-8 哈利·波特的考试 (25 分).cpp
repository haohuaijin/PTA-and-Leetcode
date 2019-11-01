#include <iostream>
using namespace std;
const int INFO = 100000;
struct MGraph{
    int Nv;
    int Ne;
    int G[100][100];
};
int book[100];
void Floyd(MGraph Graph,int D[][100]){
    int i,j,k;
    for(i=0;i<Graph.Nv;i++)
        for(j=0;j<Graph.Nv;j++)
            D[i][j] = Graph.G[i][j];
    for(k=0;k<Graph.Nv;k++)
        for(i=0;i<Graph.Nv;i++)
            for(j=0;j<Graph.Nv;j++)
                if(D[i][k] + D[k][j] < D[i][j])
                    D[i][j] = D[i][k] + D[k][j];
}
int main(){
    MGraph Graph;
    int V,W,Weight;
    int Max,MaxMin,index;
    int D[100][100];
    scanf("%d%d",&Graph.Nv,&Graph.Ne);
    //初始化
    for(int i = 0;i < Graph.Nv;i++){
        for(int j = 0;j < Graph.Nv;j++){
            if(i == j)
                Graph.G[i][j] = 0;
            else
                Graph.G[i][j] = INFO;
        }
    }
        
    for(int i=0;i<Graph.Ne;i++){
        scanf("%d%d%d",&V,&W,&Weight);
        Graph.G[V-1][W-1] = Weight;
        Graph.G[W-1][V-1] = Weight;
    }
    Floyd(Graph,D);
    MaxMin = INFO;
    for(int i=0;i<Graph.Nv;i++){
        Max = 0;
        for(int j=0;j<Graph.Nv;j++){
           if(D[i][j] > Max)
                Max = D[i][j];
        }
        if(MaxMin > Max){
            MaxMin = Max;
            index = i;
        } 
    }
    if(MaxMin == INFO) printf("0\n");
    else printf("%d %d\n",index+1,MaxMin);
    system("pause");
    return 0;
}