#include <cstdio>

int main(){
    int n,num[1001];
    scanf("%d",&n);
    for(int i = 0; i < n; i++){
        scanf("%d",&num[i]);
    }

    int a1 = 0,a2 = 0,a3 = 0,a4 = 0,a5 = 0,count[5]={0};
    int temp = 1;
    for(int i = 0; i < n; i++){
        if(num[i] % 10 == 0){
                a1 += num[i];
                count[0]++;
        }else if(num[i] % 5 == 1){
            if(temp % 2 == 0){
                a2 -= num[i];
            }else{
                a2 += num[i];
            }
            temp++;
            count[1]++;
        }else if(num[i] % 5 == 2){
            a3++;
        }else if(num[i] % 5 == 3){
            a4 += num[i];
            count[3]++;
        }else if(num[i] % 5 == 4 && a5 < num[i]){
            a5 = num[i];
            count[4]++;
        }
    }
    if(count[0] == 0) printf("N ");
    else printf("%d ",a1);
    if(count[1] == 0) printf("N ");
    else printf("%d ",a2);
    if(a3 == 0) printf("N ");
    else printf("%d ",a3);
    if(count[3] == 0) {
        printf("N ");
    }else{ 
        printf("%.1f ",(double)a4 / count[3]);
    }
    if(count[4] == 0) printf("N\n");
    else printf("%d\n",a5);
}