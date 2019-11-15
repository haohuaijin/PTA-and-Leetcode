#include <iostream>
using namespace std;
const int MAX = 110;
int N,a[MAX],b[MAX],c[MAX];
int count = 65535;
bool Check(){
    bool flag = true;
    for(int i = 0;i < N;i++){
        if(a[i] != b[i]){
            flag = false;
            break;
        }
    }
    if(flag) return true;
    else return false;
}
void Print(int x){
    if(x == 1){
        cout << "Insertion Sort" << endl;
        cout << a[0];
        for(int i=1;i<N;i++)
            cout << ' ' << a[i];
        cout << endl;
    }
    else if (x == 0){
        cout << "Heap Sort" << endl;
        cout << a[0];
        for(int i=1;i<N;i++)
            cout << ' ' << a[i];
        cout << endl;
    }
}
void Insert_Sort(){ //插入排序
    int i,j;
    bool flag = true;
    for(i = 1;i < N;i++){
        int tmp = a[i];
        for(j = i;j > 0 && a[j-1] > tmp;j--)
            a[j] = a[j - 1];
        a[j] = tmp;
        flag = Check();
        if(count == i-1){
            Print(1);
            break;
        }
        if(flag) count = i;
    }
}
void Swap(int &a,int &b){
    int tmp = a;a = b;b = tmp;
}
void PerDown(int index,int N){
    int Parenet,Child;
    int tmp = a[index];
    for(Parenet = index;(Parenet*2+1) < N;Parenet = Child){
        Child = Parenet*2 + 1;
        if((Child != N-1) && (a[Child] < a[Child+1]))
            Child++;
        if(a[Child] <= tmp) break;
        else a[Parenet] = a[Child];
    }
    a[Parenet] = tmp;
}
void Heap_Sort(){
    int i;
    bool flag = true;
    for(i = N/2 - 1;i >= 0;i--) //为什么N和N-1相同
        PerDown(i,N);
    for(i = N - 1;i > 0;i--){
        Swap(a[0],a[i]);
        PerDown(0,i);
        flag = Check();
        if(count == i+1){
            Print(0);
            break;
        }
        if(flag) count = i;
    }
}
int main(){
    scanf("%d",&N);
    for(int i = 0;i < N;i++)
        scanf("%d",&a[i]);
    for(int i = 0;i < N;i++)
        scanf("%d",&b[i]);
    for(int i = 0;i < N;i++)
        c[i] = a[i];
    Insert_Sort();
    count = 65535;
    for(int i = 0;i < N;i++)
        a[i] = c[i];
    Heap_Sort();
    /*
    for(int i=0;i<N;i++)
        cout << a[i] << ' ';
    cout << endl;*/
    system("pause");
    return 0;
}
