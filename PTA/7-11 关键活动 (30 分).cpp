#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
const int MAX = 110;
struct Edge{
    int s,e,cost,index,motive;
    Edge() {}
    Edge(int x,int y,int z,int m=0,int n=0):s(x),e(y),cost(z),index(m),motive(n) {}
};
int N,M,indegree[MAX],outdegree[MAX];
int sorted[MAX],earliest[MAX],lastliest[MAX]; 
vector<Edge> E;
vector<Edge> KeyPath;
bool compare(Edge a,Edge b){ //对输出结果排序
    if(a.s != b.s){
        return a.s < b.s; //升序
    } else {
        return a.index > b.index; //降序
    }
}
bool TopSorted(){ //拓扑排序
    int count = 0;
    queue<int> q;
    for(int i=1;i<=N;i++){//顶点从一编号
        if(indegree[i] == 0){
            q.push(i);
            sorted[count++] = i;
        }
    }
    while(!q.empty()){
        int temp = q.front();
        q.pop();
        for(int i=0;i<M;i++){
            if(indegree[E[i].e] != 0 && E[i].s == temp){
                indegree[E[i].e]--;
                if(indegree[E[i].e] == 0){
                    q.push(E[i].e);
                    sorted[count++] = E[i].e;
                }
            }
        }
    }
    if(count == N) return true;
    else return false;
}
int main(){
    int v1,v2,c,weight = 0;
    bool result;
    scanf("%d%d",&N,&M);
    for(int i=0;i<M;i++){
        scanf("%d%d%d",&v1,&v2,&c);
        E.push_back(Edge(v1,v2,c,i));
        indegree[v2]++; //入度统计
        outdegree[v1]++; //出度统计
    }
    result = TopSorted();
    if(!result){
       printf("0\n");
    } else {
        for(int i=0;i<N;i++){ //计算earliest[],用sorted[i]里的数据
            int Max = 0;
            for(int j=0;j<M;j++){
                if(E[j].e == sorted[i] && E[j].cost+earliest[E[j].s] > Max){
                    Max = E[j].cost + earliest[E[j].s];
                }
            }
            earliest[sorted[i]] = Max;
        }
        for(int i=1;i<=N;i++){ //对每个出度为零的点,lastliest[]赋值
            if(outdegree[i] == 0){
                lastliest[i] = earliest[i];
            }
        }
        for(int i=N-2;i>=0;i--){ //计算lastliest[]
            int Min = 65535; 
            for(int j=0;j<M;j++){
                if(E[j].s == sorted[i] && lastliest[E[j].e] - E[j].cost < Min){
                    Min = lastliest[E[j].e] - E[j].cost;
                }
            }
            lastliest[sorted[i]] = Min;            
        }
        for(int i=0;i<M;i++)  //计算边的机动时间
            E[i].motive = lastliest[E[i].e] - E[i].cost - earliest[E[i].s];
        for(int i=1;i<=N;i++) //输出结果
            if(earliest[i] > weight)
                weight = earliest[i];
        printf("%d\n",weight);
        for(int i=0;i<M;i++)
            if(E[i].motive == 0)
                KeyPath.push_back(E[i]);
        sort(KeyPath.begin(),KeyPath.end(),compare); //对输出结果排序
        for(auto it = KeyPath.begin();it != KeyPath.end();it++)
            printf("%d->%d\n",it->s,it->e);
    }
    system("pause");
    return 0;
}