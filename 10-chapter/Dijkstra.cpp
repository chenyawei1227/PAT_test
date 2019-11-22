/**
 * 狄杰斯特拉算法
 * */
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int n; //n为顶点数，
const int MAXV = 1000;
const int INF = 1000000000;

int d[MAXV];    //起点到达各个点点最短路径长度
bool vis[MAXV] = {false};   //标记数组，true表示已经访问，false表示没有访问

/**
 * 邻接矩阵版本
 * */
int n, G[MAXV][MAXV];   //MAXV为最大顶点数

void Dijkstra(int s){
    fill(d, d + MAXV, INF);
    d[s] = 0;
    for(int i = 0; i < n; i++){
        int u = -1, MIN = INF;
        for(int j = 0; j < n; j++){ //找到结点d[]中路径最小的
            if(vis[j] == false && d[j] < MIN){
                u = j;
                MIN = d[j];
            }
        }
        if(u == -1) return;
        vis[u] = true;
        for(int v = 0; v < n; v++){
            if(vis[v] == false && d[u] + G[u][v] < d[v]){
                d[v] = d[u] + G[u][v]; //优化d[v]
            }
        }
    }
}

/**
 * 邻接表版
 * */
struct Node{
    int v, dis; //v为边的目标顶点，dis为边权
};
vector<Node> Adj[MAXV];
void Dijkstra2(int s){
    fill(d, d + MAXV, INF); //将整个数组d[]赋值为INF
    d[s] = 0;
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
        for(int v = 0; v < Adj[u].size(); v++){
            int w = Adj[u][v].v;
            if(vis[v] == false && d[u] + Adj[u][v].dis < d[w]){
                d[v] = d[u] + Adj[u][v].dis;
            }
        }
    }
}

/**
 * 保存每个顶点的前驱结点
 * */
int pre[MAXV];  //pre[v]表示起点到顶点v的最短路径上v的最短路径上v的前一个顶点
void Dijkstra(int s){
    fill(d, d + MAXV, INF);
    for(int i=0; i<n; i++){ //初始状态设每个点的前驱为自身
        pre[i] = i;
    }
    d[s] = 0;
    for(int i=0; i<n; i++){
        int u = -1, MIN = INF;
        for(int j=0; j<n; j++){
            if(vis[j] == false && d[j] < MIN){
                u = j;
                MIN = d[j];
            }
        }
        if(u == -1) return;
        vis[u] = true;
        for(int v = 0; v < n; v++){
            if(vis[v] == false && G[u][v] != INF && d[u] + G[u][v] < d[v]){
                d[v] = d[u] + G[u][v];
                pre[v] = u;
            }
        }
    }
}
/**
 * 求最短路径
 * */
void DFS(int s, int v){
    if(v == s){
        printf("%d\n",s);
        return;
    }
    DFS(s, pre[v]);
    printf("%d\n",v);
}

/**
 * 新增边权
 * */
int cost[MAXV][MAXV];   //表示u->v的花费（由题目输入）
int c[MAXV];    //记录从起点s到达顶点u的最少花费为c[u]
void Dijkstra(int s){
    fill(d, d + MAXV, INF);
    d[s] = 0;
    for(int i=0; i<n; i++){
        int u = -1, MIN = INF;
        for(int j=0; j<n; j++){
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
                    c[v] = c[u] + cost[u][v];
                }else if(d[u] + G[u][v] == d[v] && c[u] + cost[u][v] < c[v]){
                    c[v] = c[u] + cost[u][v];
                }
            }
        }
    }
}


/**
 * 新增点权
 * */
int weight[MAXV];   //表示u的物质数目
int w[MAXV];    //记录从起点s到达顶点u的能收集到的最大物资
void Dijkstra(int s){
    fill(d, d + MAXV, INF);
    d[s] = 0;
    for(int i=0; i<n; i++){
        int u = -1, MIN = INF;
        for(int j=0; j<n; j++){
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
                }else if(d[u] + G[u][v] == d[v] && w[u] + weight[v] < w[v]){
                    w[v] = w[u] + weight[v];
                }
            }
        }
    }
}




/**
 *  求最短路径条数
 * */
int num[MAXV];    //记录从起点s到达顶点u的最短路径条数
void Dijkstra(int s){
    fill(d, d + MAXV, INF);
    d[s] = 0;
    for(int i=0; i<n; i++){
        int u = -1, MIN = INF;
        for(int j=0; j<n; j++){
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
                    num[v] = num[u];
                }else if(d[u] + G[u][v] == d[v]){
                    num[v] += num[u];
                }
            }
        }
    }
}