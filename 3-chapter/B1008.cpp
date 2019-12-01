#include <cstdio>

int main(){
    int n,m,A[101],count = 0;
    scanf("%d%d",&n,&m);
    m = m % n;
    for(int i = 0; i < n; i++){
        scanf("%d",&A[i]);
    }
    for(int i = n - m; i < n; i++){
        printf("%d",A[i]);
        count++;
        if(count < n) printf(" ");
    }
    for(int i = 0; i < n - m; i++){
        printf("%d",A[i]);
        count++;
        if(count < n) printf(" ");
    }

    return 0;
}