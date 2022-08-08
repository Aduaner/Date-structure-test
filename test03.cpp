#include"duan.h"
using namespace duan;
/*
问题描述：
    发现长度为n(n>=1)的整数数组中，未出现过的最小正整数
算法思想：
算法一：
    先对系列进行排序，然后找到最小的正整数，
    如果不是1，则return 1；
    如果是1，则向后+1扫描，直到发现不匹配项，返回结果
    时间复杂度为O(n*n),空间复杂度为O(1)
算法二：
    用空间换取时间，定义b[n],实现对0~n之间数字的标记
    然后扫描数组b，找到最小未被标记的元素
    时间复杂度为O(n),空间复杂度为O(n)
*/
int findMinMiss_1(int a[],int n){
    int temp;
    //冒泡排序
    for(int i = 0; i<n; i++){
        for(int j = i; j < n-i-1; j++){
            if(a[j] > a[j+1]){
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
    //扫描最小正整数
    int minmiss = 1;
    for(int i = 0; i<n; i++){
        if(a[i] > 0){
            if(a[i] != 1){
                return 1;
            }
            else{
                for(; i<n;){
                    if(a[++i] != ++minmiss){
                        return minmiss;
                    }
                }
            }
        }
    }
    //可能全为复整数
    return 1;
}

int findMinMiss_2(int a[], int n){
    int b[n] = {0};
    //出现过的元素在b中标记为1
    for(int i = 0; i<n; i++){
        if(a[i]>0 && a[i]<=n){
            b[a[i]-1] = 1;
        }
    }
    //扫描b中最小为0的元素
    for(int i = 0; i<n; i++){
        if(b[i] == 0){
            return i+1;
        }
    }
}
int main(){
    int s[6] = {1,-8,2,-4,3,-6};
    int minmiss;
    minmiss = findMinMiss_2(s, 6);
    cout <<"MinMiss=" <<minmiss <<endl;
    return 0;
}
