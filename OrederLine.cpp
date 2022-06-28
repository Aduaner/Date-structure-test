#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;
#define InitSize 100
#define ElemType int

//线性表结构体
typedef struct{
    ElemType *data;
    int MaxSize,length;
} SeqList;

void InitList(SeqList &L);
bool gennerlist(SeqList &L, int n);
int Rand_range(int a,int b);
bool ListInsert(SeqList &L, int i, ElemType e);
bool ListDelete(SeqList &L, int i, ElemType &e);
bool PrintList(SeqList L);
bool Empty(SeqList L);
int LocateMin(SeqList L);
bool mindel(SeqList &L,ElemType &minelem);

//P17 T1 删除最小的元素
int main(){
    SeqList L,&list=L;
    ElemType e,&elem=e;
    int n=10;
    InitList(list);
    gennerlist(list,n);
    printf("\n顺序表数列：");
    PrintList(L);
    if(Empty(L)){
        printf("\nEmpty list!");
        return 0;
    }
    else{
        mindel(list,elem);
        printf("\n删除了最小元素%d",elem);
        return 1;
    }
}

//删除最小的元素
bool mindel(SeqList &L,ElemType &minelem){
    if(L.length==0){
        printf("\nEmpty list!");
        return false;
    }
    int min_index=0;
    for(int i=1; i<L.length; i++){
        if(L.data[min_index]>L.data[i]){
            min_index=i;
        }
    }
    minelem=L.data[min_index];
    L.data[min_index]= L.data[--L.length];
    return true;
}

//生成随机n个元素的随机队列
bool gennerlist(SeqList &L, int n){
    ElemType e;
    srand((unsigned)time(NULL));
    for(int i=0;i<n;i++){
        e=Rand_range(1,15);
        L.data[i]=e;
        L.length++;
    }
    return true;
}

//随机a到b的数
int Rand_range(int a,int b){
    return a+rand()%(b-a);
}

//线性表初始化
void InitList(SeqList &L){
    L.data = new ElemType[InitSize];
    L.length =0;
    L.MaxSize = InitSize;//最大长度为初始设定
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
        if(L.length==0){
            return true;
        }
        else 
            return false;
    }

    //销毁线性表
    bool DestroyList(SeqList &L){
        delete L.data;
        L.length=0;
        free(&L);
        if(&L){
            return true;
        }
        else{
            return false;
        }
    }

    //定位最小元素的位置
    int LocateMin(SeqList L){
        int min_index=0;
        for(int i=1; i<L.length; i++){
            if(L.data[min_index]>L.data[i]){
                min_index=i;
            }
        }
        return min_index+1;
    }