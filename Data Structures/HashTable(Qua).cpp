/**
 * 散列函数: 32的位数次方
 * 解决冲突: 平方探测
 * 我认为在散列单元要用Key和Data,
 * Key: 索引, 用散列处理
 * Data: 存放数据
 */
#include <iostream>
#include <cmath>
using namespace std;
const int MAXTABLESIZE = 100000; //散列最大的长度
typedef int ElementType; //关键词用整型
typedef int Index; //散列地址类型
typedef Index Position; //数据在的位置与散列的类型一样
//散列的单元状态类型,分别对应:有合法元素,空单元,有已删除的元素
typedef enum{Legitimate,Empty,Deleted} EntryType;

typedef struct HashEntry Cell; //散列单元的类型
struct HashEntry{
    ElementType Data; //数据
    EntryType Info; //单元状态
};

typedef struct TblNode *HashTable; //散列表类型
struct TblNode{    //散列表节点定义
    int TableSize; //表的最大长度
    Cell *Cells;   //存放散列单元数据的数组
};

Index Hash(ElementType Key,int Size){
    int h = 0;
    while(Key != 0){
        h = (h<<5) + Key%10;
        key /= 10;
    }
    return h%Size;
}

int NextPrime(int N){
    //返回大于N不超过MAXTABLESIZE的最小素数
    int i,p = (N%2)?(N+2):(N+1); //从大于N的下一个素数开始

    while(p <= MAXTABLESIZE){
        for(i=(int)sqrt(p); i>2; i--)
            if(!(p%i)) break; //p不是素数
        if(i == 2) break; //正常退出,p是素数
        else p += 2; //尝试下一个
    }
    return p;
}

HashTable CreateTable(int TableSize){
    HashTable H;
    int i;

    H = (HashTable)malloc(sizeof(struct TblNode));
    //保证散列表是素数大小
    H->TableSize = NextPrime(TableSize);
    //声明单元数组
    H->Cells = (Cell*)malloc(H->TableSize*sizeof(Cell));
    //初始化空单元
    for(i=0;i<H->TableSize;i++)
        H->Cells[i].Info = Empty;

    return H;
}

Position Find(HashTable H,ElementType Key){
    Position CurrentPos,NewPos;
    int CNum = 0; //记录冲突次数

    NewPos = CurrentPos = Hash(Key,H->TableSize); //初始散列的位置
    //当该单元的位置非空,并且不是要找的元素时,发生冲突
    while(H->Cells[NewPos].Info != Empty && H->Cells[NewPos].Data != Key){ //如果是String用strcmp
        //统计一次冲突,平方探测
        if(++CNum%2){ //奇数次冲突
            NewPos = CurrentPos + (CNum+1)*(CNum+1)/4; 
            if(NewPos >= H->TableSize) //是不是没有必要
                NewPos = NewPos % H->TableSize;
        } else { //偶数次冲突
            NewPos = CurrentPos - CNum*CNum/4;
            while(NewPos < 0)
                NewPos += H->TableSize;
        }
    }
    return NewPos; //此时NewPos或为空,或是Key的位置
}

bool Insert(HashTable H,ElementType Key){
    Position Pos = Find(H,Key); //检查Key是不是存在

    if(H->Cells[Pos].Info != Legitimate){ //如果没有被占,则可以插入
        H->Cells[Pos].Info = Legitimate;
        H->Cells[Pos].Data = Key; // String用函数
        return true;
    } else {
        printf("键值已经存在\n");
        return false;
    }
}
int main(){


    system("pause");
    return 0;
}