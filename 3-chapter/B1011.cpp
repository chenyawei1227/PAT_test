#include <cstdio>

int v[100];
int main()
{
    int t;
    scanf("%d",&t);
    for(int i = 0; i < t; i++){
        long long a,b,c;
        scanf("%lld%lld%lld", &a, &b, &c);
        if(a + b > c){
            v[i+1] = 1;
        }else{
            v[i+1] = 0;
        }
    }
    for(int i = 1; i <= t; i++){
        if(v[i] == 1){
            printf("Case #%d: true\n",i);
        }else{
            printf("Case #%d: false\n",i);
        }
    }
    return 0;
}
