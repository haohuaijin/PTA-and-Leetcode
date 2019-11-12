#include <iostream>
using namespace std;
int main(){
    int N,a[10010];
    int Max = -1,sum = 0,start = 0,end = 0;
    scanf("%d",&N);
    for(int i=0;i<N;i++)
        scanf("%d",&a[i]);
    for(int i=0;i<N;i++){
        sum += a[i];
        if(sum < 0){
            sum = 0;
            continue;
        }
        if(sum > Max){
            Max = sum;
            end = i;
        }
    }
    sum = 0;
    for(int i=end;i>=0;i--){
        sum += a[i];
        if(sum == Max){
            start  = i;
        }
    }
    if(Max < 0) printf("0 %d %d",a[0],a[N-1]);
    else printf("%d %d %d\n",Max,a[start],a[end]);
    system("pause");
    return 0;
}