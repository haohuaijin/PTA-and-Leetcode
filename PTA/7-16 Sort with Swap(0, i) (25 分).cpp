#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    int N,a[100010],book[100010],count = 0,total = 0;
    scanf("%d",&N);
    fill(a,a+100010,0);
    fill(book,book+100010,0);
    for(int i=0;i<N;i++){
        scanf("%d",&a[i]);
        if(a[i] != i){
            count++; //记录位置不对的数
        }
    }
    for(int i=0;i<N;i++){
        if(a[i] == i){
            book[i] = 1;
            continue;
        } else{
            if(!book[i]){
                int tmp = i;
                book[i] = 1;
                while(a[tmp] != i){
                    tmp = a[tmp];
                    book[tmp] =  1;
                }
                total++; //记录环数
            }
        }
    }
    if(a[0] == 0){
        printf("%d\n",count+total);
    } else{
        printf("%d\n",count+total-2);
    }
    system("pause");
    return 0;
}
/* 柳婼
#include <iostream>
using namespace std;
int main() {
    int n, t, cnt = 0, a[100010];
    cin >> n;
    for(int i = 0; i < n; i++){
    	cin >> t;
    	a[t] = i;
    }
    for(int i = 1; i < n; i++) {
        if(i != a[i]) {
            while(a[0] != 0) {
                swap(a[0],a[a[0]]);
                cnt++;
            }
            if(i != a[i]) {
                swap(a[0],a[i]);
                cnt++;
            }
        }
    }
    cout << cnt << endl;
    system("pause");
    return 0;
}*/
