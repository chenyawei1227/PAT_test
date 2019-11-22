#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;

const int MAXN = 1000;
const int INF = 1000000000;

int G[MAXN][MAXN];
bool vis[MAXN] = {false}; //是否访问过
int d[MAXN];    //起点s到顶点u的最短路径
int num[MAXN];  //记录最短路径条数
int weight[MAXN]; //表示u的物质数量
int w[MAXN];    //记录从起点s到达顶点u的能收集到的最大物资
int n;  //顶点数

void Dijkstra(int s){
    fill(d, d + MAXN, INF); 
    memset(num, 0, sizeof(num));    
    //memset是计算机中C/C++语言初始化函数。作用是将某一块内存中的内容全部设置为指定的值， 
    //这个函数通常为新申请的内存做初始化工作。 需要头文件：string.h   
    memset(w, 0, sizeof(w));
    d[s] = 0;
    w[s] = weight[s];
    num[s] = 1;
    for(int i = 0; i < n; i++){
        int u = -1, MIN = INF;
        for(int j = 0; j < n; j++){
            if(vis[j] == false && d[j] < MIN){
                u = j;
                MIN = d[j];
            }
        }
        if(u == -1) return;
        vis[u] = true;
        for(int v = 0; v < n; v++){
            if(vis[v] == false && G[u][v] != INF){
                if(d[u] + G[u][v] < d[v]){
                    d[v] = d[u] + G[u][v];
                    w[v] = w[u] + weight[v];
                    num[v] = num[u];
                }else if (d[u] + G[u][v] == d[v]){
                    if( w[u] + weight[v] > w[v]){   //最短路径与点权无关，必须写在外面
                        w[v] = w[u] + weight[v];
                    }
                    num[v] += num[u];
                }
            }
        }
    }
}

int main(){
    int m, c1, c2;
    scanf("%d%d%d%d",&n, &m, &c1, &c2);
    for(int i = 0; i < n; i++){
        scanf("%d",&weight[i]);
    }
    int u,v;
    fill(G[0], G[0]+MAXN * MAXN, INF);
    for (int i = 0; i < m; i++){
        scanf("%d%d",&u, &v);
        scanf("%d", &G[u][v]);
        G[v][u] = G[u][v];
    }
    Dijkstra(c1);
    printf("%d %d\n",num[c2],w[c2]);
    return 0;
}