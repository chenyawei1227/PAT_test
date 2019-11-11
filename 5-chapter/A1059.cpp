#include <cstdio>
#include <cmath>

using namespace std;

/*是否为数素*/
bool isPrime(int n){
    if(n <= 1) return false;
    int x = (int)sqrt(1.0 * n);
    for(int i = 2; i <= x; i++){
        if(n % i == 0) return false;
    }
    return true;
}
const int max = 100010;
int prime[max],pNum = 0;
//bool p[max] = {0};
/*获取所有数素，保存到prime[]数组中*/
void findPrime(){
    for(int i = 1; i < max; i++){
        if(isPrime(i) == true){
            prime[pNum++] = i;
            //p[i] = true;
        }
    }
}

struct factor{
    int x,cnt; //x为质数，cot为某质数到个数
}fac[10];

int numFac = 0;
void findFactor(int n){
    int sqr = (int)sqrt(1.0 * n);
    for(int i = 0; i < pNum && prime[i] <= sqr; i++){
        if(n % prime[i] == 0){
            fac[numFac].x = prime[i];
            fac[numFac].cnt = 0;
            while(n % prime[i] == 0){
                fac[numFac].cnt++;
                n = n / prime[i];
            }
            numFac++;
        }
        if(n == 1) break;
    } 
    if(n != 1){
        fac[numFac].x = n;
        fac[numFac++].cnt = 1;
    }
}

int main(){
    int n;
    scanf("%d",&n);
    findPrime();
    // for(int i =0; i < pNum; i++){
    //     printf("%d ",prime[i]);
    // }
    findFactor(n);
    for(int i = 0; i < numFac; i++){
        printf("%d %d\n",fac[i].x,fac[i].cnt);
    }
    printf("%d=",n);
    for(int i = 0; i < numFac; i++){
        if(i > 0) printf("*");
        printf("%d",fac[i].x);
        if(fac[i].cnt > 1) printf("%d",fac[i].cnt);
        // if(i != numFac - 1){
        //     if(fac[i].cnt != 1){
        //         printf("%d^%d*",fac[i].x,fac[i].cnt);
        //     }else{
        //         printf("%d*",fac[i].x);
        //     }  
        // }else{
        //     if(fac[i].cnt != 1){
        //         printf("%d^%d\n",fac[i].x,fac[i].cnt);
        //     }else{
        //         printf("%d\n",fac[i].x);
        //     }  
        // }
    }
    printf("\n");
    return 0;    
}

