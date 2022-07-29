#include "duan.h"
using namespace duan;

//T8顺序表合并

int main(){
    SeqList L,&list=L;
    ElemType e,&elem=e;
    InitList(list);
    gennerlist(list,20);
    Order_Up(list);
    printf("\n顺序表L数列：\n");
    PrintList(L);

    SeqList R,S;
    InitList(R);
    InitList(S);
    gennerlist(R,10);
    Order_Up(R);
    //printf("\n顺序表R数列：\n");
    //PrintList(R);

    if(Empty(L)){
        printf("\nEmpty list!");
        return 0;
    }
    else{
        cout << "\n查找元素x:";
        cin >>e;
        SeaMid_Exc_ins(list,e);
        printf("\n顺序表数列S：\n");
        PrintList(L);
        return 1;
    }
}