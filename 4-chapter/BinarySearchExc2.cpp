/*
木棒分割问题
*/
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int f(int A[],int n,int K){
    sort(A,A + n);
    int mixLen = A[0],k,len;
    do{
        k = 0;
        for (int i = 0; i < n; i++){
            k = k + A[i] / mixLen;
        }
        len = mixLen;
        mixLen--;
    }while(k < K);
    return len;
}

int main(){
    int A[10];
    int n,K;
    scanf("%d%d",&n,&K);
    for(int i = 0; i < n; i++){
        scanf("%d",&A[i]);
    }
    printf("%d\n",f(A,n,K));
    return 0;
}