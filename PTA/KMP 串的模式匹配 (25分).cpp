#include <iostream>
#include <cstring>
using namespace std;
typedef int Position;
const int NotFound = -1;
void BuildMatch(char *Pattern,int *match){
    int m = strlen(Pattern);
    int i,tmp;
    match[0] = -1;
    // printf("%s\n",Pattern);
    for(i = 1;i < m;i++){ //注意这里的tmp和i代表什么
        tmp = match[i-1];
        while((tmp >= 0) && Pattern[i] != Pattern[tmp+1])
            tmp = match[tmp];
        if(Pattern[i] == Pattern[tmp+1]) match[i] = tmp + 1;
        else match[i] = -1;
    }
    // for(int i=0;i<m;i++)
    //     cout << match[i] << endl;
}
Position KMP(char *String,char *Pattern){
    int n = strlen(String);
    int m = strlen(Pattern);
    int s,p,*match;
    match = (int*)malloc(sizeof(int)*m);
    if(n < m) return NotFound;
    BuildMatch(Pattern,match);
    s = 0; p = 0;
    while(s < n && p < m){
        if(String[s] == Pattern[p]) {s++; p++;}
        else if(p > 0) p = match[p-1] + 1;
        else s++;
    }
    return (p == m) ? (s-m) : NotFound;
}

int main(){
    char *String,*Pattern;
    int N;
    Position index;
    String = (char*)malloc(sizeof(char)*1000010);
    Pattern = (char*)malloc(sizeof(char)*100010);
    scanf("%s",String);
    getchar();
    // printf("%s\n",String);
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        scanf("%s",Pattern);
        getchar();
        // printf("%s\n",Pattern);
        index = KMP(String,Pattern);
       if(index != NotFound) printf("%s\n",String + index);
       else printf("Not Found\n");
    }
    system("pause");
    return 0;
}