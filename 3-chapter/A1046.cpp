#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 100005;
int dis[maxn],A[maxn];

int main(){
    int sum = 0,n,m,left,right;
    scanf("%d",&n);
    for(int i = 1; i <= n; i++){
        scanf("%d",&A[i]);
        sum += A[i];
        dis[i] = sum;
    }
    scanf("%d",&m);
    for(int i = 0; i < m; i++){
        scanf("%d%d", &left, &right);
        if(left > right) swap(left,right);
        int len = dis[right - 1] - dis[left - 1];
        printf("%d\n",min(len, sum - len));
    }
    return 0;
}