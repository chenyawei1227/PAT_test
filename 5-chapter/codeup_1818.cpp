#include <cstdio>

int gcb(int a,int b){
    if (b == 0) 
    {
        return a;
    }else{
        return gcb(b, a % b);
    }
}

int main(){
    int a,b,res,lcm;
    scanf("%d%d",&a,&b);
    res = gcb(a,b); //最大公约数
    lcm = a / res * b;  //为最小公倍数
    printf("%d %d\n",res,lcm);
    return 0;
}