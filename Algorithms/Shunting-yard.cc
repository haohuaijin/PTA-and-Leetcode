// wiki: https://zh.wikipedia.org/wiki/%E8%B0%83%E5%BA%A6%E5%9C%BA%E7%AE%97%E6%B3%95
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int get_prio(const char c){
    switch(c){
        case '*':  case '/':
            return 2;
        case '+': case '-':
            return 1;
    }
    return 0; //处理'('，在出栈的时候，+-*/的优先级都高于'('，所以'('不会在没有遇到')'的时候出栈
}

string shunting_yard(string str){
    string ret;
    stack<char> stack;
    int len = str.size();
    for(int i=0; i<len; ++i){
        if(str[i] >= 'a' && str[i] <= 'z'){
            ret += str[i];
        } else if(str[i] == '('){
            stack.push(str[i]);
        } else if(str[i] == ')'){
            while(stack.top() != '('){
                ret += stack.top();
                stack.pop();
            }
            stack.pop();
        } else if (str[i] == '+' || str[i] == '-' || str[i] == '/' || str[i] == '*'){
            while(!stack.empty() &&  get_prio(str[i]) <= get_prio(stack.top())){
                ret += stack.top();
                stack.pop();
            }
            stack.push(str[i]);
        }
    }
    while(!stack.empty()){
        ret+= stack.top();
        stack.pop();
    }
    return ret;
}

int main(){
    string str1 = "a+b-a*((c+d)/e-f)+g";
    cout << "The init str: " << str1 << endl;
    cout << shunting_yard(str1) << endl;
    string str2 = "a/b+(c*d-e*f)/g";
    cout << "The init str: " << str2 << endl;
    cout << shunting_yard(str2) << endl;
    return 0;
}