#include <cstdio>

const int maxn = 2010;

int main(){
    int n,e,count = 0;
    double k, a[maxn] = {0}, c[maxn] = {0};
    scanf("%d",&n);
    for(int i = 0; i < n; i++){
        scanf("%d%lf",&e, &k);
        a[e] = k;
    }
    scanf("%d",&n);
    for(int i = 0; i < n; i++){
        scanf("%d%lf",&e, &k);
        for(int j = 0; j <= 2000; j++){
            if(a[j] != 0){
                c[e + j] += k * a[j];
            }
        } 
    }
    for(int i = 0; i <= 2000; i++){
        if(c[i] != 0){
            count++;
        }
    }
    printf("%d",count);
    for(int i = 2000; i >= 0; i--){
        if(c[i] != 0){
            printf(" %d %0.1lf",i, c[i]);
        }
    }
    return 0;
}