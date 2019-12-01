#include <cstdio>

int main(){

    long long A,B,Da,Db,Pa = 0,Pb = 0;

    scanf("%lld%lld%lld%lld", &A, &Da, &B, &Db);
    long long temp;
    do{
        temp = A % 10;
        if(temp == Da){
            Pa = Pa * 10 + Da;
        }
        A = A / 10;
    }while(A > 0);

    do{
        temp = B % 10;
        if(temp == Db){
            Pb = Pb * 10 + Db;
        }
        B = B / 10;
    }while(B > 0);
    printf("%lld\n",Pa + Pb);
    return 0;
}