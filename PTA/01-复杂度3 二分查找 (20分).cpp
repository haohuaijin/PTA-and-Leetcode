#include <iostream>
using namespace std;
#define MAXSIZE 10
#define NotFound 0
typedef int ElementType;

typedef int Position;
typedef struct LNode *List;
struct LNode {
    ElementType Data[MAXSIZE];
    Position Last; /* 保存线性表中最后一个元素的位置 */
};

List ReadInput(); /* 裁判实现，细节不表。元素从下标1开始存储 */


Position BinarySearch(List L, ElementType X){
    int start,end,centre;
    start = 0;
    end = L->Last;
    while(start < end){
        centre = (start+end)/2;
        if(L->Data[centre] > X) end = centre-1; //已经排除的元素,不要再考虑 end=centre
        else if(L->Data[centre] < X) start = centre+1;
        else return centre;
    }
    return NotFound;
}



int main()
{
    List L;
    ElementType X;
    Position P;

    L = ReadInput();
    scanf("%d", &X);
    P = BinarySearch( L, X );
    printf("%d\n", P);

    system("pause");
    return 0;
}