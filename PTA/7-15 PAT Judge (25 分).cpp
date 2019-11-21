#include <iostream>
#include <algorithm>
using namespace std;
int N,K,M,fullmark[6];
int mark[10010][6],score[10010],id[10010],prefect[10010],flag[10010];
bool cmp(int a,int b){ //排序函数
    if(score[a] != score[b]){
        return score[a] > score[b];
    } else if(prefect[a] != prefect[b]){
        return prefect[a] > prefect[b];
    } else {
        return a < b;
    }
}
int main(){
    int ids,problem_id,marks; //临时变量
    int rank[10010]; // 排名
    scanf("%d%d%d",&N,&K,&M);
    for(int i=1;i<=K;i++)
        scanf("%d",&fullmark[i]);
    
    fill(mark[0],mark[0]+10010*6,-2); //注意这里对二维数组的初始化,-2代表没提交过
    fill(score,score+10010,0); //初始化总分数
    fill(prefect,prefect+10010,0); // 初始化完美解绝方案的个数

    for(int i=1;i<=N;i++)
        id[i] = i; //记录排序的结果
    
    for(int i=0;i<M;i++){ //读入数据,perfect
        scanf("%d%d%d",&ids,&problem_id,&marks);
        if(marks == fullmark[problem_id] && mark[ids][problem_id] != marks){
            prefect[ids]++;
        }
        if(marks > mark[ids][problem_id]){
            mark[ids][problem_id] = marks;
        }
    }

    for(int i=1;i<=N;i++){//计算score
        for(int j=1;j<=K;j++){
            if(mark[i][j] > -1){
                score[i] += mark[i][j];
                flag[i]++; //标记至少有一次编译通过
            }
        }
    }  

    sort(id+1, id+N+1, cmp);
    
    for(int i=1;i<=N;i++){
        if(flag[id[i]] == 0) break; //没有一次编译通过
        if(score[id[i]] == score[id[i-1]]) rank[id[i]] = rank[id[i-1]];
        else rank[id[i]] = i;
        printf("%d %05d %d",rank[id[i]],id[i],score[id[i]]);
        for(int j=1;j<=K;j++){
            if(mark[id[i]][j] == -2) cout << ' ' << '-';
            else if(mark[id[i]][j] == -1) cout << ' ' << 0;
            else cout << ' ' << mark[id[i]][j]; 
        }
        cout << endl;
    }
    system("pause");
    return 0;
}