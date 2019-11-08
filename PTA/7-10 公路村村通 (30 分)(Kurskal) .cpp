#include <iostream>
#include <algorithm>
using namespace std;
const int MAX = 1010;
int N,M,Weight,Parenet[MAX];
struct Edge{
    int s,e,cost;
    Edge(){}
    Edge(int x,int y,int z):s(x),e(y),cost(z) {}
}edge[3*MAX];
int Find(int a){ //路径压缩
    if(Parenet[a] > 0)
        return Parenet[a] = Find(Parenet[a]);
    else return a;
}
void Union(int a,int b){ //传进来的就是根,按秩求并 
    if(Parenet[a] >= Parenet[b]){
        Parenet[b] += Parenet[a];
        Parenet[a] = b; 
    } else {
        Parenet[a] += Parenet[b];
        Parenet[b] = a;
    }
}
bool cmp(Edge a,Edge b){
    return a.cost < b.cost;
}
void Kurskal(){
    int count = 0,k = 0;
    int root1,root2;
    sort(edge,edge+M,cmp);
    fill(Parenet+1,Parenet+N+1,-1);
    while(count < N-1){
        root1 = Find(edge[k].s);
        root2 = Find(edge[k].e);
        if(root1 == root2){
            k++;
            if(k == M)  break;
            continue;
        }
        Union(root1,root2);
        Weight += edge[k].cost;
        k++;
        count++; //记录收了,几条边
        if(k == M)  break; //问什么这里是 k == M 而上面是 k == M - 1
    }
    if(count == N-1) printf("%d\n",Weight);
    else printf("-1\n");
}
int main(){
    int v1,v2,c;
    scanf("%d%d",&N,&M);
    for(int i=0;i<M;i++){
        scanf("%d%d%d",&v1,&v2,&c);
        edge[i] = Edge(v1,v2,c);
    }
    Kurskal();
    system("pause");
    return 0;
}