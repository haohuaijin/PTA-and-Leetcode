/**
 * note the 1 is not prime,but 2 is prime.
 */

#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>
using namespace std;
//Hash 输入key,和散列标的大小,得到索引
int Hash(int key,int size){
    return key%size;
}
//输入N,如果当前是素数则返回当前元素,否则返回下一个素数
int NextPrime(int N){ 
    int p,j;
    p = (N%2)?N:N+1;
    if(N == 1 || N == 2) return 2; //note the 1 is not prime,but 2 is prime.
    while(p < 100*N){
        for(j=(int)sqrt(p);j>1;j--)
            if(p%j == 0) break;
        if(j == 1) break;
        else p++;
    }
    return p;
}
// data,一开始存放数据,然后存放地址(addr),index存放地址(addr)对应的key
void Insert(int index[],int data[],int MSize,int N){
    int addr,curraddr,key,p;
    for(int i=0;i<N;i++){
        key = data[i];
        addr = Hash(key,MSize);
        curraddr = addr;
        if(index[curraddr] == -1) data[i] = curraddr;  
        else {
            p = 0; //使用前先初始化
            while(index[curraddr] != -1){
                p++;
                if(p*p >= INT_MAX-1) break; //the p*p don't more than INT_MAX. 
                //Probing must be based on the origin address in every time.
                curraddr = (addr + p*p)%MSize; 
            }
            if(index[curraddr] == -1) data[i] = curraddr;
            else data[i] = -1;
        }
        index[curraddr] = key;
    }
}
int main(){
    int MSize,N,*index,*data;
    scanf("%d%d",&MSize,&N);
    MSize = NextPrime(MSize);

    index = (int*)malloc(sizeof(int)*MSize); //数据的地址
    data = (int*)malloc(sizeof(int)*N); //数据的值

    fill(index, index+MSize,-1);

    for(int i=0;i<N;i++){
        scanf("%d",&data[i]);
    }

    Insert(index,data,MSize,N);

    cout << data[0];
    for(int i=1;i<N;i++){
        if(data[i] != -1) cout << ' ' << data[i];
        else cout << ' ' << '-'; 
    }
    cout << endl;
    
    system("pause");
    return 0;
}