#include <iostream>
#include <cmath>
using namespace std;
const int KEYLENGTH = 15;
typedef char ElementType[KEYLENGTH+1]; //关键词类型用字符串
typedef int Index; //散列地址类型
typedef struct LNode *PtrToLNode;
struct LNode{
    ElementType Data;
    PtrToLNode Next;
};
typedef PtrToLNode Position;
typedef PtrToLNode List;

typedef struct TblNode *HashTable; //散列表类型
struct TblNode{
    int TableSize;
    List Heads;
};

HashTable CreateTable(int TableSize){
    HashTable H;
    int i;

    H = (HasTable)malloc(sizeof(struct TblNode));
    H->TableSize = NextPrime(TableSize);

    H->heads = (List)malloc(h->TableSize*sizeof(struct LNode));
    for(i = 0;i<H->TableSize;i++){
        H->heads[i].Data[0] = '\0';
        H->heads[i].Next = NULL;
    }
    return H;
}


int main(){

    system("pause");
    return 0;
}