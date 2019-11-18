#include <cstdio>
#include <queue>
using namespace std;

/**
 *  最小带权路径长度
 *  哈夫曼树构造思想：反复选择两个最小的元素，合并，直到只剩下一个元素
 * */

priority_queue<long long, vector<long long>, greater<long long> > q;

int main(){
    int n;
    long long temp, x, y, ans = 0;
    scanf("%d",&n);
    for(int i = 0; i < n; i++){
        scanf("%lld",&temp);
        q.push(temp);
    }
    while(q.size() > 1){
        x = q.top();
        q.pop();
        y = q.top();
        q.pop();
        q.push(x + y);
        ans += x + y;
    }
    printf("%lld\n",ans);
    return 0;
}