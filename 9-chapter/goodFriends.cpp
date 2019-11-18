#include <cstdio>

const int N = 110;
int farther[N];
bool isRoot[N];
void init(int n){
    for(int i = 0; i <= N; i++){
        farther[i] = i;
        isRoot[i] = false;
    }
}

int findFarther(int x){
    while(x != farther[x]){
        x = farther[x];
    }
    return x;
}

int findFarther2(int x){
    int a = x;
    while(x != farther[x]){
        x = farther[x];
    }
    //压缩路径
    while(a != farther[a]){
        int z = a;
        a = farther[a];
        farther[z] = x;
    }
    return x;
}

void Union(int a, int b){
    int faA = findFarther(a);
    int faB = findFarther(b);
    if(faA != faB){
        farther[faA] = faB;
    }
}

int main(){
    int n,m,a,b;
    scanf("%d%d",&n,&m);
    init(n);
    for(int i = 0; i < m; i++){
        scanf("%d%d",&a,&b);
        Union(a,b);
    }
    for(int i = 0; i < n; i++){
        isRoot[findFarther(i)] = true;
    }
    int ans = 0;
    for(int i = 0; i < n; i++){
        ans += isRoot[i];
    }
    printf("%d\n",ans);
    return 0;
}