#include <cstdio>

int main(){
    int t,a,aa,b,bb;
    int na = 0,nb = 0;
    scanf("%d",&t);
    for(int i = 0; i < t; i++){
        scanf("%d%d%d%d",&a, &aa, &b, &bb);
        if(aa == a + b && bb == a + b){
            continue;
        }else if(aa == a + b){
            nb++;
        }else if(bb == a + b){
            na++;
        }
    }
    printf("%d %d\n", na, nb);
    return 0;
}

