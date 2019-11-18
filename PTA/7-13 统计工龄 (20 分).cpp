#include <iostream>
using namespace std;
const int MAX = 55;
int book[MAX];
int main(){
    int N,num;
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        scanf("%d",&num);
        book[num]++;
    }
    for(int i=0;i<MAX;i++){
        if(book[i] != 0){
            printf("%d:%d\n",i,book[i]);
        }
    }
    system("pause");
    return 0;
}