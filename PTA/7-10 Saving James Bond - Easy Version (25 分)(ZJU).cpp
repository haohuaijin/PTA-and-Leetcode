#include <iostream>
#include <cmath>
using namespace std;
struct Graph{
    int X,Y;
    bool book;
};
bool IsSave(Graph V,int Dist){ //能否到岸
    return (pow(V.X,2) <= pow(Dist,2) || pow(V.Y,2) <= pow(Dist,2) || \
        pow(100-V.X,2) <= pow(Dist,2) || pow(100-V.Y,2) <= pow(Dist,2));
}
bool IsCanJump(Graph V1,Graph V2,int Dist){ //能否从V1跳到V2
    return pow(V1.X-V2.X,2) + pow(V1.Y-V2.Y,2) <= pow(Dist,2);
}
bool DFS(int index,int Nv,int Dist,Graph G[]){
    bool answer = false;
    G[index].book = true;
    if(IsSave(G[index],Dist)){
        answer = true;
    } else {
        for(int i = 1;i <= Nv; i++){
            if(!G[i].book && IsCanJump(G[index],G[i],Dist)){
                answer = DFS(i,Nv,Dist,G);
                if(answer == true) break;
            }
        }
    }
    return answer;
}
bool IsCenterJump(Graph V,int Dist){ //计算从中心跳出
    return pow(V.X-50,2) + pow(V.Y-50,2) <= pow(Dist + 7.5,2);
}
bool Save007(int Nv,int Dist,Graph G[]){ // 对起点特殊处理
    bool answer = false;
    G[0].book = true;
    for(int i = 1; i <= Nv; i++){
        if(!G[i].book && IsCenterJump(G[i],Dist)){
            answer = DFS(i,Nv,Dist,G);
            if(answer == true) break;
        }
    }
    return answer;
}
int main(){
    int Nv,Dist,x,y;
    int answer;
    Graph G[101]; //发生了一次运行时错误,指针越界
    G[0].X = G[0].Y = 50;
    scanf("%d%d",&Nv,&Dist);
    for(int i = 1; i <= Nv; i++){
        scanf("%d%d",&x,&y);
        G[i].X = x + 50;
        G[i].Y = y + 50;
        G[i].book = false;
    }
    answer = Save007(Nv,Dist,G);
    if(answer) printf("Yes\n");
    else printf("No\n");
    system("pause");
    return 0;
}