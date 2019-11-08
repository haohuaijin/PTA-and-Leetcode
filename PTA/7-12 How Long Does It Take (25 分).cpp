#include <iostream>
#include <queue>
using namespace std;
const int INFI = 65535;
const int MAX = 110;
int N,M,Graph[MAX][MAX];
int Sorted[MAX],indegree[MAX],Earliest[MAX];
bool Topological(){ //拓扑排序
    int count = 0;
    queue<int> q;
    for(int i=0;i<N;i++){
        if(indegree[i] == 0){
            q.push(i);
            Sorted[count++] = i;
        }
    }
    while(!q.empty()){
        int temp = q.front();
        q.pop();
        for(int i=0;i<N;i++){
            if(indegree[i] != 0 && Graph[temp][i] != INFI){
                indegree[i]--;
                if(indegree[i] == 0){
                    q.push(i);
                    Sorted[count++] = i;
                }
            }
        }
    }
    if(count == N) return true;
    else return false;
}
int main(){
    bool result;
    int v1,v2,weight;
    scanf("%d%d",&N,&M);
    for(int i=0;i<N;i++) //注意那个数是顶点数
        for(int j=0;j<N;j++)
            if(i == j) Graph[i][j] = 0;
            else Graph[i][j] = INFI;
    for(int i=0;i<M;i++){ //有向图
        scanf("%d%d%d",&v1,&v2,&weight);
        Graph[v1][v2] = weight;
        indegree[v2]++;
    }
    result = Topological();
    if(!result)
        printf("Impossible\n");
    else{ //根据拓扑排序，求出最长的时间
        for(int i=0;i<N;i++){
            int MAX = 0;
            for(int j=0;j<N;j++){ 
                //🕔在这里浪费时间了。没有判断好条件，把Earliest[j] 写成了 Earliest[Sorted[j]]
                //所以这种关键的地方，要想好再写。
                if(Graph[j][Sorted[i]] != INFI && MAX < Earliest[j] + Graph[j][Sorted[i]]){
                    MAX = Earliest[j] + Graph[j][Sorted[i]];
                }
            }
            Earliest[Sorted[i]] = MAX;
        }
        int earliest = 0;
        for(int i=0;i<N;i++){
            if(Earliest[i] > earliest)
                earliest = Earliest[i];
        }
        printf("%d\n",earliest);
    }

    system("pause");
    return 0;
}