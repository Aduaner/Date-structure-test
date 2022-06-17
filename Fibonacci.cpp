#include<iostream>
using namespace std;
#define MAX 30
//递归算法
int Fibonacci(int n){
    if(n==0||n==1){
        return 1;
    }
    else{
        return Fibonacci(n-1)+Fibonacci(n-2);
    }
}

//非递归算法
int Fibo(int n){
    int a[MAX]={1,1};
    if(n==0||n==1){
        return 1;
    }
    else{
        for(int i=2;i<=n;i++){
            a[i]=a[i-1]+a[i-2];
        }
        return a[n];
    }
}

int main(void){
    int n;
    int f1,f2;
    cout << "输入斐波那契数列的项数(n):"<< endl;
    cin >>n;
    f1=Fibonacci(n);//递归算法
    f2=Fibo(n);//非递归算法
    cout << "F1("<<n<<")="<<f1<<endl;
    cout << "F2("<<n<<")="<<f2<<endl;
    return 0;
}