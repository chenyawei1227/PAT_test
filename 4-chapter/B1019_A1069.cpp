#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;
bool cmp(int a,int b){
    return a > b;
};

int main(){
    int N,A[10],n = 4;
    scanf("%d",&N);
    while(1){
        int numC = 0,numD = 0;
        for(int i = 0; i < n; i++){
            A[i] = N % 10;
            N = N / 10;
        }
        sort(A,A + n,cmp);
        for(int i = 0; i < n; i++){
            numC = numC*10 + A[i];
        }
        for(int i = n -1; i >= 0; i--){
            numD = numD*10 + A[i];
        }
        N = numC - numD;
        printf("%d - %d = %04d\n",numC, numD, N);
        if(N == 0 || N == 6174){
            break;
        }
    }
    return 0;
}