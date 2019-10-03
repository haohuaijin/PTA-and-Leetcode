#include <stdio.h>
#include <stdlib.h>
/**
 * 带有头结点 
 */
typedef struct Node *Stack;
struct Node{
    char s;
    Stack Next;
};
//操作
Stack CreateStack(); //初始化栈
void Push(Stack p,char str); //入栈
int IsEmpty(Stack p); //判断是不是为空
char Pop(Stack p); //出栈
char GetTop(Stack p); //得到栈顶元素
void majoy(Stack p,char *s); //后缀表达式

int main()
{
    Stack p = CreateStack();
    char S[50] = {0};
    scanf("%[^\n]",S);
    majoy(p,S); //得到后缀表达式
    system("pause");
    return 0;
}

//后缀表达式
void majoy(Stack p,char *S)
{
    int flag = 0;
    char *ptr = S;
    while(*ptr)
    {
        //处理数字
        if((*ptr >= '0' && *ptr <= '9') || *ptr == '.') 
        {
            if(flag) printf(" ");
            //处理小数点
            while((*ptr >= '1' && *ptr <= '9') || *ptr == '.'){
                printf("%c",*ptr);
                ptr++;
                flag = 1;
            }

        }
        /* 可有可无，为了防止指针错误可以用这个
        //处理开始的-5 
        else if((*ptr == '-' || *ptr == '+') && ptr == S)
        {
        	ptr++;
        	if(*(ptr-1) == '+') printf("");
            else printf("-");
            while((*ptr >= '1' && *ptr <= '9') || *ptr == '.'){
                printf("%c",*ptr);
                ptr++;
                flag = 1;
            }
		}*/
        //专门处理-5这种情况
        else if((*ptr == '-' || *ptr == '+') && (*(ptr-1)>'9' || *(ptr-1)<'0') && *(ptr-1) != ')' && (*(ptr+1)>='1' && *(ptr+1)<='9'))
        {
            ptr++;
            if(flag) printf(" ");
            if(*(ptr-1) == '+') printf("");
            else printf("-");
            while((*ptr >= '1' && *ptr <= '9') || *ptr == '.'){
                printf("%c",*ptr);
                ptr++;
                flag = 1;
            }
        }
        //处理左括号
        else if(*ptr == '(')
        {
            Push(p,*ptr);
            ptr++;
        }
        //处理右括号
        else if(*ptr == ')')
        {
            //将里面的全部抛出
            while(GetTop(p) != '(')
            {
                printf(" %c",Pop(p));
            }
            Pop(p);
            ptr++;
        }
        //处理加减号
        else if(*ptr == '-' || *ptr == '+')
        {
            //处理空栈，或遇到左括号
            if(IsEmpty(p) || GetTop(p) == '(')
            {
                Push(p,*ptr);
                ptr++;
            }
            //全部抛出直到空栈或左括号
            else
            {
                while(!IsEmpty(p))
                {
                    if(GetTop(p) == '(') break;
                    else printf(" %c",Pop(p));
                }
                Push(p,*ptr);
                ptr++;
            }
        }
        //处理乘除号
        else if(*ptr == '*' || *ptr == '/')
        {
            //处理空栈，或遇到左括号
            if(IsEmpty(p) || GetTop(p) == '(')
            {
                Push(p,*ptr);
                ptr++;
            }
            //遇到加减号同上
            else if(GetTop(p) == '-' || GetTop(p) == '+')
            {
                Push(p,*ptr);
                ptr++;
            }
            //处理出栈的情况
            else
            {
                while(!IsEmpty(p) && (GetTop(p) == '*' || GetTop(p) == '/'))
                {
                    if(GetTop(p) == '(') break;
                    else printf(" %c",Pop(p));
                }
                Push(p,*ptr);
                ptr++;
            }
        }
    }
    //最后输出剩下运算符
    while(!IsEmpty(p))
    {
        printf(" %c",Pop(p));
    }
}

//初始化栈
Stack CreateStack()
{
    Stack q;
    q = (Stack)malloc(sizeof(struct Node));
    q->s = '\0';
    q->Next = NULL;
    return q;
}

//入栈
void Push(Stack p,char str)
{
    Stack ptr;
    ptr = CreateStack();
    ptr->s = str;
    ptr->Next = p->Next; //注意指向的位置
    p->Next = ptr;
}

//出栈
char Pop(Stack p)
{
    Stack ptr;
    char str;
    if(IsEmpty(p)){
        printf("栈空\n");
        return '\0';
    }
    ptr = p->Next;
    str = ptr->s;
    p->Next = ptr->Next;
    free(ptr);
    return str;
}

//判断是不是为空
int IsEmpty(Stack p)
{
    return (p->Next == NULL);
}

//得到栈顶元素
char GetTop(Stack p)
{
    if(IsEmpty(p)) return '\0';
    else return p->Next->s;
}