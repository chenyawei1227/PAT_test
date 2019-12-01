#include <cstdio>

int main(){
    int n;
    scanf("%d",&n);
    long long a, b, c;
    long long res;
    bool flag;
    for(int i = 1; i <= n; i++){
        scanf("%lld%lld%lld", &a, &b, &c);
        res = a + b;
        if(a > 0 && b > 0 && res < 0) flag = true; //正溢出
        else if(a < 0 && b < 0 && res >= 0) flag = false; //负溢出,res要大于等于0
        else if(res > c) flag = true;
        else flag = false; 
        if(flag == true){
            printf("Case #%d: true\n",i);
        }else{
            printf("Case #%d: false\n",i);
        }
    }
    return 0;
}