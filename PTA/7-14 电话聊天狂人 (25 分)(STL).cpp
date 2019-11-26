#include <iostream>
#include <map>
#include <unordered_map> //时间少,占内存少
using namespace std;
int main(){
    int Max = 0,Count = 0;
    long long int N,num1,num2,Key;
    unordered_map<long long int,int> q;
    scanf("%lld",&N);
    for(int i=0;i<N;i++){
        scanf("%lld%lld",&num1,&num2);
        q[num1]++;
        q[num2]++;
    }
    for(auto it = q.begin();it != q.end();it++){
        if(it->second > Max)
            Max = it->second;
    }
    Key = 19999999999;
    for(auto it = q.begin();it != q.end();it++){
        if(it->second == Max){
            Count++;
            if(it->first < Key)
                Key = it->first;
        } 
    }
    cout << Key << ' ' << Max;
    if(Count != 1) cout << ' ' << Count << endl;
    system("pause");
    return 0;
}
/*
4 
13005711862 13588625832 
13505711862 13088625832 
13588625832 18087925832 
15005713862 13588625832
*/