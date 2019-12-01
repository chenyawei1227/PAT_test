#include <cstdio>

int main(){
    int n,m;
    double a[1010] = {},b[1010] = {},c[1010] = {};
    
    int e,count = 0;
    double k;
    scanf("%d",&n);
    for(int i = 0; i < n; i++){
        scanf("%d%lf",&e, &k);
        a[e] = k;
    }
    scanf("%d",&m);
    for(int i = 0; i < m; i++){
        scanf("%d%lf",&e, &k);
        b[e] = k;
    }
    for(int i = 1000; i >= 0; i--){
        c[i] = a[i] + b[i];
    }
    for(int i = 1000; i >= 0; i--){
        if(c[i] != 0){
            count++;
        }
    }
    printf("%d",count);
    for(int i = 1000; i >= 0; i--){
        if(c[i] != 0){
            printf(" %d %0.1lf",i, c[i]);
            count--;
        }
    }
    return 0;
}

/**
 * #include <cstdio>

int main(){
    int n,m;
    double c[1010] = {};
    int e,count = 0;
    double k;
    scanf("%d",&n);
    for(int i = 0; i < n; i++){
        scanf("%d%lf",&e, &k);
        c[e] += k;
    }
    scanf("%d",&m);
    for(int i = 0; i < m; i++){
        scanf("%d%lf",&e, &k);
        c[e] += k;
    }
    for(int i = 1000; i >= 0; i--){
        if(c[i] != 0){
            count++;
        }
    }
    printf("%d",count);
    for(int i = 1000; i >= 0; i--){
        if(c[i] != 0){
            printf(" %d %0.1lf",i, c[i]);
            count--;
        }
    }
    return 0;
}
 * */