#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> q[1010];
int N,book[1010],HashTable[1010];
void BackInput(){
    int i,k,Min,flag = 0;
    while(1){
        Min = 65537;
        k = -1;
        for(i=0;i<N;i++){
            if(q[i].empty() && !book[i] && HashTable[i] < Min){
                Min = HashTable[i];
                k = i;
            }
        }
        if(k == -1) break; //loop end
        if(!flag++) cout << Min;
        else cout << ' ' << Min;
        book[k] = 1;
        for(int i=0;i<N;i++){
            auto it = find(q[i].begin(),q[i].end(),k);
            if(it != q[i].end()) q[i].erase(it);
        }
    }
    cout << endl;
}
int main(){
    int tmp;
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        scanf("%d",&HashTable[i]);
        if(HashTable[i] == -1){
            q[i].push_back(-1);
            continue;
        } 
        tmp = HashTable[i]%N;
        while(tmp != i){
            q[i].push_back(tmp++);
            tmp = tmp%N;
        }
    }
    BackInput();
    system("pause");
    return 0;
}