#include"duan.h"
using namespace duan;
/*
算法说明:
    三元组(a,b,c), a b c分别取自S1 S2 S3(三个升序序列)
    三元组的距离公式D=|a-b|+|b-c|+|c-a|
    求所有三元组中，距离最小的三元组，及其距离
分析：本质上是最大蒜素与最小元素距离的二倍，计算极值即可
*/
int abs(int x, int y) {
    if(x < y)
        return y-x;
    else
        return x-y;
}

int Distance(int x, int y, int z){
    int D;
    D=abs(x,y)+abs(y,z)+abs(z,x);
    return D;
}
//三层循环的笨方法
int findMinDistance1(int S1[], int l1, int S2[], int l2, int S3[], int l3){
    int minCombin[3] = {S1[0], S2[0], S3[0]}, minDistance, D;
    minDistance = Distance(S1[0], S2[0], S3[0]);
    for(int i=0;i<l1;i++){
        for(int j=0;j<l2;j++){
            for(int k=0;k<l3;k++){
                D = Distance(S1[i], S2[j], S3[k]);
                if(minDistance>D){
                    minDistance = D;
                    minCombin[0] = S1[i];
                    minCombin[1] = S2[j];
                    minCombin[2] = S3[k];
                }
            }
        }
    }
    cout <<'('<<minCombin[0]<<','<<minCombin[1]<<','<<minCombin[2]<<')'<<endl;
    return minDistance;
}
//最小项移位对比的方法，空间复杂度O(n)
int findMinDistance2(int S1[], int l1, int S2[], int l2, int S3[], int l3){
    int a, b, c;
    a = S1[0];
    b = S2[0];
    c = S3[0];
    int i = 0, j = 0, k = 0;
    int minD = Distance(S1[0], S2[0], S3[0]),D;
    while(i<l1 || j<l2 || k<l3){
        D = Distance(S1[i], S2[j], S3[k]);
        if(D<minD){
            minD = D;
        }
        if(S1[i]<=S2[j] && S1[i]<=S3[k])
            i++;
        else if(S2[j]<=S3[k] && S2[j]<=S1[i])
            j++;
        else k++;
    }
    return minD;
}

int main(){
    int S1[3] = {-1,0,9}, 
        S2[4]={-25,-10,10,11}, 
        S3[5]={2,9,17,30,41};
    int minD1 = findMinDistance1(S1,3,S2,4,S3,5);
    int minD2 = findMinDistance2(S1,3,S2,4,S3,5);
    cout<<minD1<<endl;
    cout<<minD2<<endl;
    return 0;
 }