#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * ջ����ͷ��� 
 */

//����ջ 
typedef struct Node *Stack;
struct Node{
	char Str;
	Stack Next;
};
//���� 
Stack CreateStack(); //�����ڵ�
void Push(Stack ptr,char s); //��ջ 
char Pop(Stack ptr); //��ջ 
int IsEmpty(Stack p); //�ж��ǲ��ǿյ� 
void prepro(char *q,char *prep); //Ԥ���� 
char Look(Stack ptr); //�鿴ջ��Ԫ�� 
char *ReadStr(); //�������� 

int main()
{
	Stack p;
	char temp; //��������Pop 
	p = CreateStack();
//	char S[1000] = "void test(){int i, A[10];for (i=0; i<10;i++)/**/A[i] = i}.";
	char prep[200] = {0}; //Ԥ�����ַ��� 
	char *S;
	S = ReadStr(); 
	prepro(S,prep); 
//	printf("%s\n",prep);
	char *q = prep;
	//�жϴ��� 
	while(*q)
	{
		if(*q == '(' || *q == '{' || *q == '[' ){	//��ջ 
			Push(p,*q);
			q++;
			continue;
		} else if(*q == '/' && *(q+1) == '*'){	//����/* 
			Push(p,'/');
			q = q+2; //����Խ�� 
			continue;
		} else if(*q == ')'){	//���� ) 
			temp = Look(p);
			if(temp == '0') {printf("NO\n?-)\n");return 0;}
			if(temp == '(') {Pop(p);}
			else {printf("NO\n%c-?\n",temp);return 0;} 
			q++;
			continue;
		} else if(*q == ']'){	//���� ] 
			temp = Look(p);
			if(temp == '0') {printf("NO\n?-]\n");return 0;}
			if(temp == '[') {Pop(p);}
			else {printf("NO\n%c-?\n",temp);return 0;} 
			q++;
			continue;
		} else if(*q == '}'){	//���� } 
			temp = Look(p);
			if(temp == '0') {printf("NO\n?-}\n");return 0;}
			if(temp == '{') {Pop(p);}
			else {printf("NO\n%c-?\n",temp);return 0;} 
			q++;
			continue;
		} else if(*q == '*' && *(q+1) == '/'){	//���� */ 
			temp = Look(p);
			if(temp == '0') {printf("NO\n?-*/\n");return 0;}
			if(temp == '/') {Pop(p);}
			else {printf("NO\n%c-?\n",temp);return 0;} 
			q = q+2;
			continue;
		} else if(*q == '/' && *(q-1) == '*'){	//���� /*/ 
			printf("NO\n/*-?\n");
			return 0;
		} else {q++;continue;}
	}
	//�����жϣ�������ջ�ǲ��ǿյ� 
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

//������� 
Stack CreateStack()
{
	Stack p;
	p = (Stack)malloc(sizeof(struct Node));
	p->Str = '\0';
	p->Next = NULL;
	return p;
}

//��ջ 
void Push(Stack ptr,char s)
{
	Stack p;
	p = CreateStack();
	p->Str = s;
	p->Next = ptr->Next;
	ptr->Next = p;
}
 
//��ջ 
char Pop(Stack ptr)
{
	char s;
	if(IsEmpty(ptr)) return '0'; //����ֵ 
	Stack p = ptr->Next;
	s = p->Str;
	ptr->Next = p->Next;
	free(p);
	return s;
}

//�ж��ǲ��ǿյ� 
int IsEmpty(Stack p)
{
	return (p->Next == NULL); 
} 

//Ԥ���� 
void prepro(char *S,char *prep)
{
	char temp_prep[200];
	char *q = S;
	char temp[2] = "1";
	while(*q) //���޹ص��ַ�ȥ�� 
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
	while(*q) //��*����˷���ȥ�� 
	{
		if(*q == '*' && *(q-1) == '*' && *(q+1) == '*') q++; //����/***/ ������/****/ 
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
	if(IsEmpty(ptr)) return '0'; //����ֵ 
	Stack p = ptr->Next;
	return p->Str;
} 

//��������
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
		//Str[i-2]ע���±���ж� 
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





























 
