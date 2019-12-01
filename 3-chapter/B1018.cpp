#include <cstdio>

int change(char c){
    if(c == 'B') return 0;
    if(c == 'C') return 1;
    if(c == 'J') return 2;
}

int main(){
    int n;
    char m[3] = {'B','C','J'};
    char c1,c2;
    int handA[3] = {0}, handB[3] = {0}; //靠哪个手势赢的次数
    int times_A[3] = {0}, times_B[3] = {0}; //甲乙的 0胜，1平，2负的次数
    int k1,k2;
    scanf("%d",&n);
    for(int i = 0; i < n; i++){
        getchar(); //吸收空格
        scanf("%c %c", &c1, &c2);
        k1 = change(c1);
        k2 = change(c2);
        if((k1 + 1) % 3 == k2){
            times_A[0]++;
            times_B[2]++;
            handA[k1]++;
        }else if(k2 == k1){
            times_A[1]++;
            times_B[1]++;
        }else{
            times_A[2]++;
            times_B[0]++;
            handB[k2]++;
        }
    }
    printf("%d %d %d\n", times_A[0], times_A[1], times_A[2]);
    printf("%d %d %d\n", times_B[0], times_B[1], times_B[2]);
    int d1=0,d2=0;
    for(int i = 0; i<3; i++){
        if(handA[d1] < handA[i]){
            d1 = i;
        }
        if(handB[d2] < handB[i]){
            d2 = i;
        }
    }
    printf("%c %c\n",m[d1], m[d2]);
    return 0;
}