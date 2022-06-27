#include "duan.h"
using namespace orderline;

bool gennerlist(SeqList &L, int n);
int Rand_range(int a,int b);

//P17 T1 删除最小的元素
int mian(){
    SeqList L,&list=L;
    ElemType e,&elem=e;
    int n=10;
    InitList(list);
    gennerlist(list,n);
    printf("/n顺序表数列：");
    PrintList(L);
    if(Empty(L)){
        printf("\nEmpty list!");
        return 0;
    }
    else{
        ListDelete(list,LocateMin(L),elem);
        printf("\n删除了最小元素%d",elem);
        return 1;
    }
}

//生成随机n个元素的随机队列
bool gennerlist(SeqList &L, int n){
    ElemType e;
    for(int i=0;i<n;i++){
        e=Rand_range(0,20);
        if(!ListInsert(L,L.length+1,e)){
            return false;
        }
    }
    return true;
}
//随机a到b的数
int Rand_range(int a,int b){
    return a+rand()%(b-a);
}