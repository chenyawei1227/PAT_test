#include <cstdio>
#include <cmath>
using namespace std;
//
// bool isPrime(int n){
//     if(n <= 1) return false;
//     int sqr = (int)sqrt(1.0 * n);
//     for(int i = 2; i <= sqr; i++){
//         if(n % i == 0){
//             return false;
//         }
//     }
//     return true;
// }
// const int max = 100010;
// int prime[max],Pnum = 0;
// void findPrime(){
//     for(int i = 2; i < max; i++){
//         if(isPrime(i) == true){
//             prime[Pnum++] = i; 
//         }
//     }
// }
const int maxn = 1000010;
int prime[maxn],num = 0;
bool p[maxn] = {0};
void Find_Prime(int n){
    for(int i =2; i < maxn; i++){
        if(p[i] == false){
            prime[num++] = i;
            if(num >= n) break;
            for(int j = i + 1; j < maxn; j = j + i){
                p[j] = true;//埃式筛选法 ：把数素的整数倍都去掉
            }
        }
    }
}
int main(){
    int m,n,count = 0;
    scanf("%d%d",&m,&n);
    Find_Prime(n);
    for(int i = m; i <= n; i++){  
        count++; 
        printf("%d",prime[i - 1]);//下表从0开始
        if(count % 10 != 0 && i < n){
            printf(" ");
        }else{
            printf("\n");
        }
    }
    return 0;
}