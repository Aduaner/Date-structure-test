#include "duan.h"
using namespace duan;

/*
设计一个递归算法，删除不带头结点的单链表L中所有值为x的结点
*/

void deleteLList_x(LinkList &L, int x){
    if(L->data == x){

    } 
    if(L!= NULL){

    }
}

int main(){
    LinkList L;
    LNode *newNode,*prevNode;
    int Data[10] = {1,2,3,4,5,6,3,2,4,4};
    L = (LNode*)malloc(sizeof(LNode));
    for(int i=0; i<10; i++){
        if(i==0){
            L.data = Data[i];
            prevNode = L;
        }
        newNode = (LNode*)malloc(sizeof(LNode));
        newNode->data = Data[i];
        prevNode->next = newNode;
    }
    
}