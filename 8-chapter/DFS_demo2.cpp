#include <cstdio>
#include <vector>

using namespace std;

const int maxn = 100010;
int n,k,x,maxSumSqu = -1,A[maxn];
vector<int> temp,ans;
/*
给定N个整数（可能有负数），从中选择K个数，使得这K个数之和恰好等于一个给定的整数X；
如果有多种方案，选择它们中元素平方和最大的一个。数据保证结果唯一.
*/
void DFS(int index, int nowK, int sum, int sumSqu){
    if(nowK == k && sum == x){
        if(sumSqu > maxSumSqu){
            maxSumSqu = sumSqu;
            ans = temp;
        }
        return;
    }
    if(index == n || nowK > k || sum > x) return;
    temp.push_back(A[index]);
    DFS(index + 1, nowK + 1, sum + A[index], sumSqu + A[index]*A[index]);
    temp.pop_back();
    DFS(index + 1,nowK,sum,sumSqu);
}

/*
假设N个整数中的每一个都可以被选择多次，那么选择K个数，使得K个数之和恰好为X。
*/
void DFS2(int index, int nowK, int sum, int sumSqu){
    if(nowK == k && sum == x){
        if(sumSqu > maxSumSqu){
            maxSumSqu = sumSqu;
            ans = temp;
        }
        return;
    }
    if(index == n || nowK > k || sum > x) return;
    temp.push_back(A[index]);
    DFS(index, nowK + 1, sum + A[index], sumSqu + A[index]*A[index]);//只需要修改本行代码
    temp.pop_back();
    DFS(index + 1,nowK,sum,sumSqu);
}

int main(){
    scanf("%d%d%d",&n,&k,&x);
    for(int i = 0; i < n; i++){
        scanf("%d",&A[i]);
    }
    DFS(0,0,0,0);
    printf("%lu\n",temp.size());
    printf("%lu\n",ans.size());

    for(vector<int>::iterator it=ans.begin(); it != ans.end(); it++){
        printf("%d ",*it);
    }
    printf("\n");
    return 0;
}

