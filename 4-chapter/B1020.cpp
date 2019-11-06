#include <cstdio>
#include <algorithm>

using namespace std;


struct Goods{
    double store;
    double sell;
    double price;
}goods[1000];

bool cmp(Goods a,Goods b){
    return a.price > b.price;
}

int main(){
    int n;
    double d,total;

    scanf("%d%lf",&n,&d);
    for(int i = 0; i < n; i++){
        scanf("%lf",&goods[i].store);
    }
    for(int i = 0; i < n; i++){
        scanf("%lf",&goods[i].store);
        goods[i].price = goods[i].store / goods[i].store;
    }
    sort(goods,goods + n,cmp);
    for(int j = 0; j < n; j++){
        if(d >= goods[j].store){
            total = total + goods[j].sell;
            d = d - goods[j].store;
        }else{
            total = total + d * goods[j].price;
            break;
        }
    }
    
    printf("%.2lf\n",total);
    return 0;   
}