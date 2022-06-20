#include<iostream>
using namespace std;

#define InitSize 100

#define ElemType int
//线性表结构体
typedef struct{
    ElemType *data;
    int MaxSize,length;
} SeqList;

//线性表初始化
void InitList(SeqList &L){
    L.data = new ElemType[InitSize];
    L.length =0;
    L.MaxSize = InitSize;//最大长度为初始设定
}

//线性表长度
int Length(SeqList L){
    return L.length;
}

//定位元素
int LocateElement(SeqList L, ElemType e){
    for(int i=0; i<L.length; i++){
        if(L.data[i]==e){
            return i+1;
        }
    }
    return -1;
}

//得到第i个元素
ElemType GetElem(SeqList L,int i){
    if(i>=0 && i<L.length){
        return L.data[i];
    }
    else{
        return 0;
    }
}

//插入在第i个元素的位置
bool ListInsert(SeqList &L, int i, ElemType e){
    if(i>=1 && i<=L.length && L.length+1<=L.MaxSize){
        for(int j=L.length; j>=i; j--){
            L.data[j] = L.data[j-1];
        }
        L.data[i-1]=e;
        L.length++;
        return true;
    }
    else
        return false;
}

//删除第i个元素
bool ListDelete(SeqList &L, int i, ElemType &e){
    if(i>=1 && i<=L.length){
        e=L.data[i-1];
        for(int j=i; j<L.length; j++){
            L.data[j-1]=L.data[j];
        }
        L.length--;
        return true;
    }
    else{
        return false;
    }
}

//输出线性表元素
bool PrintList(SeqList L){
    if(L.length>=1){
        for(int i=0; i<L.length; i++){
            if (i%10==0 && i!=0){
                cout <<"\n";
            }
            cout << L.data[i]<<"\t";
        }
        return true;
    }
    else 
    return false;
}

//判空
bool Empty(SeqList L){
    if(L.length=0){
        return true;
    }
    else 
        return false;
}

bool DestroyList(SeqList &L){
    delete L.data;
    free(&L);
}