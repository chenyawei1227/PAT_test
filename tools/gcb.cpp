/*
    求最大公约数公式
*/

#include <cstdio>

int gcb(int a,int b){
    if(b == 0){
        return a;
    }else{
        return gcb(b,a % b);
    }
}

int main(){
    int a,b,res;
    scanf("%d%d",&a,&b);
    res = gcb(a,b);
    printf("%d\n",res);
    return 0;
}