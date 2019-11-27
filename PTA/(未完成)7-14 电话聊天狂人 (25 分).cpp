#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
const int MAX = 158295;
const int MOD = 158291;
int Hash(long long int Key){
    return Key%MOD;
}
void InsertAndFind(long long int Key,long long int MAP[],int count[]){
    int i = 0;
    int addr = Hash(Key);
    if(count[addr] == -1){ //没有元素
        MAP[addr] = Key;
        count[addr] = 1;
    } else { //有元素
        if(MAP[addr] == Key) count[addr]++; //有元素,并且等于Key
        else { //有元素,并且不等于Key,要处理冲突
            while(MAP[addr] != -1 && MAP[addr] != Key){ //对应没出现过和出现过
                //addr = (++i + addr)%MOD;
                if(++i%2){  //平方探测
                    addr = addr + (i+1)*(i+1)/4;
                    if(addr >= MAX)
                        addr = addr%MOD;
                } else {
                    addr = addr -i*i/4;
                    while(addr < 0) //注意考虑
                        addr += MOD;
                }
            }
            if(MAP[addr] == -1){ //没出现过
                MAP[addr] = Key;
                count[addr] = 1;
            } else { //出现过
                count[addr]++;
            }
        }
    }
}
int main(){
    int N,Count,Max,count[MAX];
    long long int num1,num2,MinKey,MAP[MAX];
    scanf("%d",&N);
    fill(count, count+MAX, -1); //赋初值
    fill(MAP, MAP+MAX, -1); //赋初值
    for(int i=0;i<N;i++){
        scanf("%lld%lld",&num1,&num2);
        InsertAndFind(num1,MAP,count);
        InsertAndFind(num2,MAP,count);
    }
    Max = 0; 
    for(int i=0;i<MAX;i++){ //求出最大的次数
        if(count[i] > Max){
            Max = count[i];
        }  
    }
    Count = 0; MinKey = 19999999999;
    for(int i=0;i<MAX;i++){ //统计狂人的数量
        if(count[i] == Max){
            Count++;
            if(MAP[i] < MinKey)
                MinKey = MAP[i];
        }
    }
    cout << MinKey << ' ' << Max;
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