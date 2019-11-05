/*
*区间贪心
*/
#include <cstdio>
#include <algorithm>
using namespace std;
struct Inteval{
    int x,y;
}I[110];

bool cmpLeft(Inteval a,Inteval b){
    if(a.x != b.x){
        return a.x > b.x;
    }else{
        return a.y < b.y;
    }
}

bool cmpRight(Inteval a,Inteval b){
    if(a.y != b.y){
        return a.y < b.y;
    }else{
        return a.x > b.x;
    }
}

int main(){
    int n;
    while(scanf("%d",&n), n != 0){
        for(int i = 0; i < n; i++){
            scanf("%d%d", &I[i].x, &I[i].y);
        }
        sort(I, I + n, cmpLeft);
        int ans = 1, lastX = I[0].x;
        for(int i = 1; i < n; i++){
            if(I[i].y <= lastX){
                lastX = I[i].x;
                ans ++; 
            }
        }
        printf("%s\n","==========================");
        printf("%d\n",ans);
        sort(I, I + n, cmpRight);
        int ansr = 1, lastRX = I[0].y;
        for(int i = 1; i < n; i++){
            if(I[i].x <= lastRX){
                lastRX = I[i].y;
                ansr ++; 
            }
        }
        printf("%d\n",ansr);
    }
    return 0;
}