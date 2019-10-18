#include <stdio.h>
#include <stdlib.h>
#define INFO -100000
typedef struct{ //并查集
    int Node[10010];
    int Parenet[10010];
}Arr;
int Find(int X,Arr *Array){
    int i = 1;
    while(1){
        if(Array->Node[i] == X) break;
        i++;
    }
    for(;Array->Parenet[i] >= 0;i = Array->Parenet[i]);
    return i;
}
int main(){
    int n,c1,c2;
    char s;
    Arr Array;
    scanf("%d",&n);
    getchar();
    Array.Parenet[0] = INFO;
    for(int i=1;i<=n;i++) Array.Node[i] = i; //初始化
    while(1){
        scanf("%c",&s);
        if(s == 'S') break;
        scanf("%d %d",&c1,&c2);
        getchar();
        if(s == 'I'){
            int root1,root2;
            root1 = Find(c1,&Array);
            root2 = Find(c2,&Array);
            if(Array.Parenet[root1] == INFO && Array.Parenet[root2] == INFO){
                Array.Parenet[c1] = -2;
                Array.Parenet[c2] = c1;
            } else if(Array.Parenet[root1] == INFO){
                Array.Parenet[c1] = c2;
                Array.Parenet[c2] += -1;
            } else if(Array.Parenet[root2] == INFO){
                Array.Parenet[c2] = c1;
                Array.Parenet[c1] += -1;
            } else {
                if(Array.Parenet[root1] > Array.Parenet[root2]){
                    Array.Parenet[root2] += Array.Parenet[root1];
                    Array.Parenet[root1] = root2;
                } else{
                    Array.Parenet[root1] += Array.Parenet[root2];
                    Array.Parenet[root2] = root1;
                }
            }
        }
        else if(s == 'C'){
            int root1,root2;
            root1 = Find(c1,&Array);
            root2 = Find(c2,&Array);
            if(root1 != root2 || (root1 == 0 && root2 == 0)) printf("no\n");
            else printf("yes\n");
        }
    }

    int i = 1,count = 0,sum = 0;
    for(;i<=n;i++){
        if(Array.Parenet[i] < 0){
            sum += Array.Parenet[i];
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