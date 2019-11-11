#include <cstdio>
#include <cstring>

const int MAXN = 100010;
const int MOD = 1000000007;//为什么要模1000000007,因为在32位系统中1000000007是最小的十位质数。模1000000007，可以保证值永远在int的范围内
char str[] = {};
int leftNumP[MAXN] = {0};

int main(){

    gets(str);
    int n = strlen(str);
    for(int i = 0; i < n; i++){
        if(i > 0){
            leftNumP[i] = leftNumP[i - 1];
        }
        if(str[i] == 'P'){
            leftNumP[i]++;
        }
    }
    int ans = 0;int rightNumT = 0;
    for(int i = n -1; i >= 0; i--){
        if(str[i] == 'T'){
            rightNumT++;
        }
        if(str[i] == 'A'){
            ans = (ans + leftNumP[i] * rightNumT) % MOD;
        }
    }
    printf("%d\n",ans);
    return 0;
}