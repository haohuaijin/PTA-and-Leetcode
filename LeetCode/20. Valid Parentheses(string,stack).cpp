bool isValid(char * s){
    char *p = s;
    int top = -1;
    char stack[10000];
    char temp;
    while(*p){
        if(*p == '{' || *p == '(' || *p == '['){
            stack[++top] = *p;
            p++;
        } else {
            if(top == -1) return false; //可能就一个符号
            temp = stack[top];
            if(temp == '{' && *p == '}'){
                p++;
                top--;
                continue;
            }else if(temp == '(' && *p == ')'){
                p++;
                top--;
                continue;
            }else if(temp == '[' && *p == ']'){
                p++;
                top--;
                continue;
            } else
                return false;
        }
    }
    if(top == -1) return true;
    else return false;
}