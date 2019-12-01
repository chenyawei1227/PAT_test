#include <cstdio>

int main(){
    int c1,c2,n;
    int CLC_TCK = 100;
    scanf("%d%d",&c1, &c2);
    n = (c2 - c1);
    if(n % CLC_TCK >= 50){
        n = n / CLC_TCK + 1;
    }else{
        n = n / CLC_TCK;
    }

    printf("%02d:%02d:%02d\n",n / 3600, n % 3600 / 60, n % 60);
    return 0;
}