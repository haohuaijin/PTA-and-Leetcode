#include <iostream>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;
const int MAX = 110;
const int INFO = 1000000;
struct Node{
    int X,Y;
    Node() {} //用来不初始化定义Ver[101]
    Node(int _x,int _y) : X(_x),Y(_y) {} //用来提供X和Y的初始值
}Ver[MAX];
int Path[MAX]; //记录路径
int N,D;
bool book[MAX]; //记录是否访问
int last = -1;
queue<int> q;
bool IsVertexJump(int a,int b){ //能不能从a到b
    return (pow(Ver[a].X-Ver[b].X,2) + pow(Ver[a].Y-Ver[b].Y,2) <= pow(D,2));
}
bool IsSave(int a){ //a能不能到岸
    return (pow(Ver[a].X,2) <= pow(D,2) || pow(Ver[a].Y,2) <= pow(D,2) || \
        pow(100-Ver[a].X,2) <= pow(D,2) || pow(100-Ver[a].Y,2) <= pow(D,2));
}
int IsCenterJump(int a){ //能不能从中心跳出
    if(pow(Ver[a].X-50,2) + pow(Ver[a].Y-50,2) <= pow(D + 7.5,2))
        return (pow(Ver[a].X-50,2) + pow(Ver[a].Y-50,2));
    else 
        return 0;
}
bool cmp(int x,int y){ //排序的比较函数
    return IsCenterJump(x)<IsCenterJump(y);
}
void Save007(){ //无权图单源最短路
    int temp;
    int b[MAX]; //用来把第一跳排序
    fill(Path, Path+N+1, INFO);
    fill(book, book+N+1, false);
    Path[0] = -1;
    book[0] = true;
    if(IsSave(0)){
        last = 0;
        return;
    }
    for(int i=1;i<=N;i++){ //对第一跳排序
        b[i] = i;
    }
    sort(b+1,b+N+1,cmp); //why 第二个是N + 1,对就是N+1
    for(int i=1;i<=N;i++){ //按靠近center的顺序，放入queue
        if(IsCenterJump(b[i])){
            q.push(b[i]);
            Path[b[i]] = 0;
            book[b[i]] = true;
        }
    }
    while(!q.empty()){
        temp = q.front();
        q.pop();
        if(IsSave(temp)){ //能不能到岸
            last = temp;
            break;
        } 
        for(int i=1;i<=N;i++){
            if(!book[i] && IsVertexJump(temp,i)){
                q.push(i);
                Path[i] = temp;
                book[i] = true; //在入队时就book
            }
        }
    }
}
int main(){
    int x,y;
    int a[MAX]; //记录最短路径
    int count = 0;
    Ver[0] = Node(50,50);
    scanf("%d%d",&N,&D);
    for(int i=1;i<=N;i++){
        scanf("%d%d",&x,&y);
        Ver[i] = Node(x+50,y+50);
    }
    Save007();
    if(last == -1) printf("0\n");//输出结果
    else {
        while(last > 0){
            a[count++] = last;
            last = Path[last];
        }
        printf("%d\n",count+1);
        for(int i=count-1;i>=0;i--){
            printf("%d %d\n",Ver[a[i]].X-50,Ver[a[i]].Y-50);
        }
    }
    system("pause");
    return 0;
}