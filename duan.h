#ifndef __DUAN_H__
#define __DUAN_H__

#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
#define InitSize 100
typedef int ElemType;

namespace duan{
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

    //随机a到b的数
    int Rand_range(int a,int b){
        return a+rand()%(b-a);
    }

    //生成随机n个元素的随机队列
    bool gennerlist(SeqList &L, int n){
        ElemType e;
        srand((unsigned)time(NULL));
        for(int i=0;i<n;i++){
            e=Rand_range(1,50);
            L.data[i]=e;
            L.length++;
        }
        return true;
    }

    //顺序表倒置
    void Reverse_list(SeqList &L){
        ElemType temp;
        for(int i=0; i<L.length/2; i++){
            temp=L.data[i];
            L.data[i]= L.data[L.length-i-1];
            L.data[L.length-i-1]=temp;
        }
    }

    //P17 T3 删除指定元素x
    void del_x1(SeqList &L,ElemType x){
        int k=0;
        for(int i=0;i<L.length;i++){
            if(L.data[i]!=x){
                L.data[k]=L.data[i];
                k++;
            }
        }
        L.length=k;
    }

    void del_x2(SeqList &L,ElemType x){
        int k=0;
        for(int i=0;i<L.length;i++){
            if(L.data[i]==x){
                k++;
            }
            else{
                L.data[i-k]=L.data[i];
            }
        }
        L.length=L.length-k;
    }

    //P17 T4 删除s、t范围的元素
    bool del_range1(SeqList &L,ElemType s,ElemType t) {
        int k=0;
        if(t<=s){
            cout << "范围错误!"<<endl;
            return false;
        }
        else if(L.length==0){
            cout << "顺序表为空!"<<endl;
            return false;
        }
        else{
            for(int i=0;i<L.length;i++){
                if(L.data[i]>s&&L.data[i]<t){
                    k++;
                }
                else{
                    L.data[i-k]=L.data[i];
                }
            }
            L.length=L.length-k;
            return true;
        }
    }
    //P17 T5 删除s、t范围的元素，包含s、t
    bool del_range2(SeqList &L,ElemType s,ElemType t) {
        int k=0;
        if(t<=s){
            cout << "范围错误!"<<endl;
            return false;
        }
        else if(L.length==0){
            cout << "顺序表为空!"<<endl;
            return false;
        }
        else{
            for(int i=0;i<L.length;i++){
                if(L.data[i]>=s&&L.data[i]<=t){
                    k++;
                }
                else{
                    L.data[i-k]=L.data[i];
                }
            }
            L.length=L.length-k;
            return true;
        }
    }
    //P17 T6 删除有序表的相同元素
    void Order_Up(SeqList &L){
        ElemType temp;
        for(int i=L.length-1;i>0;i--){
            for(int j=1;j<=i;j++){
                if(L.data[j-1]>L.data[j]) {
                    temp=L.data[j];
                    L.data[j]=L.data[j-1];
                    L.data[j-1]=temp;
                }     
            }
        }
    }
    //删除重复元素
    void Del_same(SeqList &L){
        int k=0;
        for(int i=1;i<L.length;i++){
            if(L.data[k]!=L.data[i]){
                L.data[++k]=L.data[i];
            }
        }
        L.length=k+1;
    }
    //合并两个顺序表
    bool Conbin_list(SeqList L,SeqList R,SeqList &S) {
    if(L.length+R.length>S.MaxSize)
        return false;
    int k=0,i=0,j=0;
    while(i<L.length || j<R.length){
        if(i==L.length){
            while(j<R.length){
                S.data[k++]=R.data[j++];
                S.length++;
            }
            break;
        }
        else if(j==R.length){
            while(i<L.length){
                S.data[k++]=L.data[i++];
                S.length++;
            }
            break;
        }
        if(L.data[i]>R.data[j]){
            S.data[k++]=R.data[j++];
            S.length++;
        }
        else{
            S.data[k++]=L.data[i++];
            S.length++;    
        }
    }
    return true;
}
    //T8交换前数组中m和后n个数的位置
    //倒置指定数列号的元素
    void Reverse_array(ElemType A[],int left,int right,int ArraySize){
        if(left>=right ||right>ArraySize)
        return;
        int mid=(right-left)/2;
        ElemType temp;
        for(int i=0;i<mid;i++){
            temp=A[left+i];
            A[left+i]=A[right-i];
            A[right-i]=temp;
        }
    }
    //m和n更换位置
    void Exchange_array(ElemType A[],int m,int n,int ArraySize){
        Reverse_array(A,0,m+n-1,ArraySize);
        Reverse_array(A,0,n-1,ArraySize);
        Reverse_array(A,n,m+n-1,ArraySize);
    }
    //T9查找元素x，若找到与后继交换；若没找到，插入
    //顺序查找实现
    void SeaOrd_Exc_ins(SeqList &L,ElemType x){
        int i;
        for(i=0;L.data[i]<x&&i<L.length;i++);
        ElemType temp;
        if(L.data[i]==x && i<L.length-1){
            temp=L.data[i];
            L.data[i]= L.data[i+1];
            L.data[i+1]=temp;
        }
        else if(L.data[i]==x && i==L.length-1){
            cout << "无后继元素！"<<endl;
        }
        else if(i<=L.length){
            for(int j=0;L.length-1-j>=i;j++){
                L.data[L.length-j]=L.data[L.length-j-1];
            }
            L.length++;
            L.data[i]=x;
        }
    }
    //折半查找实现
    void SeaMid_Exc_ins(SeqList &L,ElemType x){
        int low=0,high=L.length-1,mid;
        ElemType temp;
        while(low<=high){
            mid=(low+high)/2;
            if(x==L.data[mid]){
                break;
            }
            else if(x<L.data[mid]){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        if(x==L.data[mid]&&x<L.length-1){
            temp=L.data[mid];
            L.data[mid]= L.data[mid+1];
            L.data[mid+1]=temp;
        }
        else if(low>high){
            for(int j=0;L.length-1-j>high;j++){
                L.data[L.length-j]=L.data[L.length-j-1];
            }
            L.length++;
            L.data[high+1]=x;
        }
    }
}

#endif

//T10 数列左循环移动
    //本质上是数组的前后p位元素的位置交换
    /*
    void Move_Left(ElemType A[],int p,int ArraySize){
        Exchange_array(A,p,ArraySize-p,ArraySize);
    }
    */