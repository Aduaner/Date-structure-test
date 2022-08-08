#include"duan.h"
using namespace duan;

/*
问题说明：
当一个整数序列中某个元素的数量大于整个序列元素个数一半时
该元素为序列的主元素，发现一个序列的主元素(长度已知)
算法说明：
方法一：先排序后统计的方法
先对序列进行排列，然后统计个数
时间复杂度O(nlog~2(n))
方法二：先扫描后检查的方法
使用int e存储可能是主元素的元素，使用count计数
扫描第一个元素，e存储，count+1
下一个元素若是e，count+1；若不是count-1
count为0时，c放入新元素，count+1
最后检查一遍，c是否是主元素
时间复杂度为O(n)
*/
int findMainElement1(int A[],int n){
    //冒泡排序
    int temp;
    for(int i=0; i<n; i++){
        for(int j=i; j<n-i-1; j++){
            if(A[j]>A[j+1]){
                temp = A[j];
                A[j] = A[j+1];
                A[j+1] = temp;
            }
        }
    }
    //统计是否存在主元素
    for(int i = 0; i<=n/2; i++){
        if(A[i]==A[i+n/2]){
            return A[i];
        }
    }
    return -1;
}
int findMainElement2(int A[],int n){
    int c,count=0;
    c = A[0];
    count++;
    for(int i = 1; i<n; i++){
        if(c == A[i]){
            count++;
        }
        else{
            count--;
        }
        if(count == 0){
            c = A[i];
            count++;
        }
    }
    count = 0;
    for(int i = 0; i<n; i++){
        if(c == A[i]){
            count++;
        }
    }
    if(count > n/2){
        return c;
    }
    else{
        return -1;
    }
}

int main(){
    int S[8]={3,4,4,3,4,3,4,4};
    int Element1 ,Element2;
    Element1=findMainElement1(S , 8);
    Element2=findMainElement2(S , 8);
    cout <<Element1 <<endl;
    cout <<Element2 <<endl;
    return 0;
}