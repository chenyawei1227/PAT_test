/*
二分查找的扩展，求根号2的值的近似值，定义域为[1,2]
*/
#include <cstdio>

const double eps = 1e-5;//10的-5次方

double f(double x){
    return x * x - 2;
}
double solve(double left, double right){
    double mid;
    while(right - left > eps){
        mid = (right + left) / 2;
        if(f(mid) > 0){
            right = mid;
        }else{
            left = mid;
        }
    }
    return mid;
}

int main(){
    double left = 1,right = 3; 
    printf("%lf\n",solve(left,right));
    return 0;
}