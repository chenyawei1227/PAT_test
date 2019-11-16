#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;
const int maxn = 110;
struct node{
    int weight;
    vector<int> child;
}Node[maxn];

bool cmp(int a, int b){
    return Node[a].weight > Node[b].weight;
}

int n,m,s;
int path[maxn];//记录路径
//index当前正在访问到结点； numNode当前路径path上的结点个数； 
void DFS(int index, int numNode, int sum){
    if(sum > s) return;
    if(sum == s){
        if(Node[index].child.size() != 0) return;//没有到叶子结点
        for(int i = 0; i < numNode; i++){
            printf("%d",Node[path[i]].weight);
            if(i < numNode - 1) printf(" ");
            else printf("\n");
        }
        return;
    }
    for(int i = 0; i < Node[index].child.size(); i++){//枚举所有子结点
        int child = Node[index].child[i];//结点index的第i的子结点编号
        path[numNode] = child;//将结点child添加到path末尾
        DFS(child, numNode + 1, sum + Node[child].weight);//递归进入下一层
    }
}

int main(){
    scanf("%d%d%d",&n,&m,&s);
    for(int i = 0; i < n; i++){
        scanf("%d",&Node[i].weight);
    }
    int id,k,child;
    for(int i = 0; i < m; i++){
        scanf("%d%d",&id,&k);
        for(int j = 0; j < k; j++){
            scanf("%d",&child);
            Node[id].child.push_back(child);
        }
        sort(Node[id].child.begin(),Node[id].child.end(),cmp);
    }
    path[0] = 0;
    DFS(0,1,Node[0].weight);
    return 0;
}