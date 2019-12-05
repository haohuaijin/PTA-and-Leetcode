#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;
int main(){
    int N;
    string str;
    char s;
    long long int num;
    unordered_map<long long int,string> q;
    scanf("%d",&N);
    getchar();
    for(int i=0;i<N;i++){
        scanf("%c %lld",&s,&num);
        cin >> str;
        getchar();
        if(s == 'N'){
            if(q.find(num) != q.end()){
                printf("ERROR: Exist\n");
            } else {
                q[num] = str;
                printf("New: OK\n");
            }
        } else {
            if(q.find(num) == q.end()){
                printf("ERROR: Not Exist\n");
            } else if(q.find(num) != q.end() && q[num] != str){
                printf("ERROR: Wrong PW\n");
            } else {
                printf("Login: OK\n");
            }
        }
        // // printf("%c %lld\n",s,num);
        // cout << str << endl;
    }
    system("pause");
    return 0;
}