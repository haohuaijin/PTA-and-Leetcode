#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * 栈带有头结点 
 */

//创建栈 
typedef struct Node *Stack;
struct Node{
	char Str;
	Stack Next;
};
//操作 
Stack CreateStack(); //创建节点
void Push(Stack ptr,char s); //入栈 
char Pop(Stack ptr); //出栈 
int IsEmpty(Stack p); //判断是不是空的 
void prepro(char *q,char *prep); //预处理 
char Look(Stack ptr); //查看栈顶元素 
char *ReadStr(); //读入数据 

int main()
{
	Stack p;
	char temp; //用来接收Pop 
	p = CreateStack();
//	char S[1000] = "void test(){int i, A[10];for (i=0; i<10;i++)/**/A[i] = i}.";
	char prep[200] = {0}; //预处理字符串 
	char *S;
	S = ReadStr(); 
	prepro(S,prep); 
//	printf("%s\n",prep);
	char *q = prep;
	//判断错误 
	while(*q)
	{
		if(*q == '(' || *q == '{' || *q == '[' ){	//入栈 
			Push(p,*q);
			q++;
			continue;
		} else if(*q == '/' && *(q+1) == '*'){	//处理/* 
			Push(p,'/');
			q = q+2; //可能越界 
			continue;
		} else if(*q == ')'){	//处理 ) 
			temp = Look(p);
			if(temp == '0') {printf("NO\n?-)\n");return 0;}
			if(temp == '(') {Pop(p);}
			else {printf("NO\n%c-?\n",temp);return 0;} 
			q++;
			continue;
		} else if(*q == ']'){	//处理 ] 
			temp = Look(p);
			if(temp == '0') {printf("NO\n?-]\n");return 0;}
			if(temp == '[') {Pop(p);}
			else {printf("NO\n%c-?\n",temp);return 0;} 
			q++;
			continue;
		} else if(*q == '}'){	//处理 } 
			temp = Look(p);
			if(temp == '0') {printf("NO\n?-}\n");return 0;}
			if(temp == '{') {Pop(p);}
			else {printf("NO\n%c-?\n",temp);return 0;} 
			q++;
			continue;
		} else if(*q == '*' && *(q+1) == '/'){	//处理 */ 
			temp = Look(p);
			if(temp == '0') {printf("NO\n?-*/\n");return 0;}
			if(temp == '/') {Pop(p);}
			else {printf("NO\n%c-?\n",temp);return 0;} 
			q = q+2;
			continue;
		} else if(*q == '/' && *(q-1) == '*'){	//处理 /*/ 
			printf("NO\n/*-?\n");
			return 0;
		} else {q++;continue;}
	}
	//用来判断，配对完后栈是不是空的 
	if(!IsEmpty(p)){
		while(p->Next != NULL)
		{
			temp = Pop(p);
		}
		printf("NO\n%c-?\n",temp);
	}else 
		printf("YES\n");
	return 0;
} 

//创建结点 
Stack CreateStack()
{
	Stack p;
	p = (Stack)malloc(sizeof(struct Node));
	p->Str = '\0';
	p->Next = NULL;
	return p;
}

//入栈 
void Push(Stack ptr,char s)
{
	Stack p;
	p = CreateStack();
	p->Str = s;
	p->Next = ptr->Next;
	ptr->Next = p;
}
 
//出栈 
char Pop(Stack ptr)
{
	char s;
	if(IsEmpty(ptr)) return '0'; //返回值 
	Stack p = ptr->Next;
	s = p->Str;
	ptr->Next = p->Next;
	free(p);
	return s;
}

//判断是不是空的 
int IsEmpty(Stack p)
{
	return (p->Next == NULL); 
} 

//预处理 
void prepro(char *S,char *prep)
{
	char temp_prep[200];
	char *q = S;
	char temp[2] = "1";
	while(*q) //将无关的字符去除 
	{
		if(*q == '(' || *q == ')'   || *q == '{'|| *q == '}' || \
			*q == '[' || *q == ']' || *q == '/'|| *q == '*')
		{
			temp[0] = *q;
			strncat(temp_prep,temp,1);		
		}
		q++;
	}
	q = temp_prep;
	while(*q) //将*代表乘法的去除 
	{
		if(*q == '*' && *(q-1) == '*' && *(q+1) == '*') q++; //处理/***/ 处理不了/****/ 
		if(*q == '*' && (*(q-1) == '/' || *(q-1) == '*') && (*(q+1) == '/' || *(q+1) == '*'))
		{
			temp[0] = *q;
			strncat(prep,temp,1);
		}
		else if(*q == '(' || *q == ')'   || *q == '{'|| *q == '}' || \
			*q == '[' || *q == ']' || *q == '/')
		{
			temp[0] = *q;
			strncat(prep,temp,1);
		}
		q++;
	}
} 

char Look(Stack ptr)
{
	if(IsEmpty(ptr)) return '0'; //返回值 
	Stack p = ptr->Next;
	return p->Str;
} 

//读入数据
char *ReadStr()
{
	char *Str;
	char *p;
	Str = (char*)malloc(sizeof(char)*1000);
	char c;
	int i=0;
	while(1)
	{
	    c = getchar();
		Str[i++] = c;
		//Str[i-2]注意下标的判断 
		if(c == '\n' && Str[i-2] == '.')
		{
			break;
		}
	}
	Str[i] = '\0';
	p = Str;
	while(*p)
	{
		if(*p == '\n')
		{
			*p = 'a';
		}
		p++;
	}
	*p = '\0';
	return Str;
}





























 
