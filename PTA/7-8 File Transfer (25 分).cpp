#include <stdio.h>
#include <stdlib.h>
#define INFO -100000
int Parenet[10001]; //储存父节点
int Find(int c1){
    for(;Parenet[c1] >= 0;c1 = Parenet[c1]);
    return c1;
}
void Union(int c1,int c2){
    int root1,root2;
    root1 = Find(c1);
    root2 = Find(c2);
    if(Parenet[root1] >= Parenet[root2]){
        Parenet[root2] += Parenet[root1]; 
        Parenet[root1] = root2;
    } else if(Parenet[root2] > Parenet[root1]){
        Parenet[root1] += Parenet[root2];
        Parenet[root2] = root1;
    }
}
int main(){
    int n,c1,c2,root1,root2;
    char S;
    Parenet[0] = INFO;
    scanf("%d",&n);
    getchar();
    for(int i=1;i<=n;i++) Parenet[i] = -1;
    while(1){
        scanf("%c",&S);
        if(S == 'S') break;
        scanf("%d %d",&c1,&c2);
        getchar();
        if(S == 'I') Union(c1,c2);
        else{
            root1 = Find(c1);
            root2 = Find(c2);
            if(root1 == root2) printf("yes\n");
            else printf("no\n");
        }
    }
    int i = 1,count = 0,sum = 0;
    for(;i<=n;i++){
        if(Parenet[i] < 0){
            sum += Parenet[i];
            count++;
        }  
    }
    if(count == 1 && sum + n == 0) printf("The network is connected.\n");    
    else{
        printf("There are %d components.\n",sum+n+count);
    }
    system("pause");
    return 0;
}