#include <stdio.h>
#include <stdlib.h>

typedef struct Node TreeNode;
struct Node{
	char name;
	char left;
	char right;
};

int main()
{
	int n;
	int i,j;
    int count = 0;
	TreeNode *Anode,*Bnode;
	
	/* 区别 */
	scanf("%d\n",&n);
	//动态分配
	Anode = (TreeNode*)malloc(sizeof(struct Node)*n);
	Bnode = (TreeNode*)malloc(sizeof(struct Node)*n);
	//输入
	for(i=0;i<n;i++){
	
		/* 区别 */
		scanf("%c %c %c\n",&Anode[i].name,&Anode[i].left,&Anode[i].right);
	//	fflush(stdin);
	}
	
	/* 区别 */
	scanf("%d\n",&n);
	for(i=0;i<n;i++){
	
		/* 区别 */
		scanf("%c %c %c\n",&Bnode[i].name,&Bnode[i].left,&Bnode[i].right);
	//	fflush(stdin);
	}
	//判断
	for(i=0;i<n;i++) //控制变化前的树
	{
		for(j=0;j<n;j++) //控制变化后的树
		{
			if(Anode[i].name == Bnode[j].name)
			{
				int Al,Ar,Bl,Br;
				Al = Anode[i].left - '0';
				Ar = Anode[i].right - '0';
				Bl = Bnode[j].left - '0';
				Br = Bnode[j].right - '0';
				//没有变化
				if(Al == Bl && Bl == Br && Br == Ar) break;

				else if(Al == Bl && Anode[Ar].name == Bnode[Br].name) break;

				else if(Anode[Al].name == Bnode[Bl].name && Ar == Br) break;

				else if(Anode[Al].name == Bnode[Bl].name &&\
					Anode[Ar].name == Bnode[Br].name) break;
				//有变化
				else if(Al == Br && Anode[Ar].name == Bnode[Bl].name) break;

				else if(Anode[Al].name == Bnode[Br].name && Ar == Bl) break;

				else if(Anode[Al].name == Bnode[Br].name &&\
					Anode[Ar].name == Bnode[Bl].name) break;
		
				else{
					printf("No\n");
					return 0;
				}
			}
		}
		if(j == n) {printf("No\n");return 0;}
	}
	printf("Yes\n");
    return 0;
}
