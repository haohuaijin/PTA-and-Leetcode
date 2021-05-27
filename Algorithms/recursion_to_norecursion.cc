//link: https://codeforces.com/topic/49210/en11
#include <iostream>
#include <stack>
#include <string>
#include <utility>
using namespace std;

int recursion_factorial(int n){
    if(n == 1){
        return 1;
    } else {
        int k = recursion_factorial(n-1);
        return n*k;    
    }
}

int norecursion_factorial(int n){
    stack<pair<int, bool>> s;
    s.push({n, true}); //true 代表还没有运行， flase 代表已经运行
    int ret = 0;
    while(!s.empty()){
        pair<int, bool> t = s.top(); s.pop();
        if(t.second == true){
            if(t.first == 1){
                ret = 1;
            } else {
                s.push({t.first, false});
                s.push({t.first-1, true});
            }
        } else if (t.second == false) {
            ret = t.first*ret;
        }
    }
    return ret;
}

int main(){
    cout << "recursion(5): " << recursion_factorial(5) << endl;
    cout << "norecursion(5): " << norecursion_factorial(5) << endl;
    return 0;
}