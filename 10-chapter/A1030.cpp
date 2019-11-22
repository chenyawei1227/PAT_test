#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;

const int MAXV = 500;
const int INF = 10000000;

int G[MAXV][MAXV];
int d[MAXV];//最短路径
bool vis[MAXV] = {false};
int n,m,st,ed;
int cost[MAXV][MAXV],W[MAXV][MAXV];//边权(即最小花费),点权

vector<int> pre[MAXV];
void Dijkstra(int s){ //s为起点
    fill(d, d + MAXV, INF);
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
        for(int v = 0; v < n; v++){
            if(vis[v] == false && G[u][v] != INF){
                if(d[u] + G[u][v] < d[v]){
                    d[v] = d[u] + G[u][v];
                    pre[v].clear();
                    pre[v].push_back(u);//令v的前驱结点为u
                }else if(d[u] + G[u][v] == d[v]){
                    pre[v].push_back(u);
                }
            }
        }
    }
}
int miniCost = INF; //第二标尺最优值
vector<int> path, tempPath; //最优路径，临时路径
void DFS(int v){ //v为当前正在访问结点
    //递归边界
    if(v == st){
        tempPath.push_back(v);
        int value = 0; //边权之和
        for(int i = tempPath.size() - 1; i > 0; i--){
            //当前结点id,下一个结点idNext
            int id = tempPath[i], idNext = tempPath[i - 1];
            value += cost[id][idNext];
        }
        // int value; //点权之和
        // for(int j = tempPath.size() - 1; j > 0; j--){
        //     int id = tempPath[j];
        //     value += W[id];
        // }
        if(value < miniCost){
            miniCost = value;
            path = tempPath;
        }
        tempPath.pop_back();
        return;
    }
    //递归式
    tempPath.push_back(v);
    for(int i = 0; i < pre[v].size(); i++){
        DFS(pre[v][i]);
    }
    tempPath.pop_back();
}

int main(){
    scanf("%d%d%d%d",&n, &m, &st, &ed);
    int c1, c2;
    fill(G[0], G[0] + MAXV * MAXV, INF); //初始化图G
    fill(cost[0],cost[0] + MAXV * MAXV, INF);
    for(int i = 0; i < m; i++){
        scanf("%d%d",&c1, &c2);
        scanf("%d%d",&G[c2][c1], &cost[c2][c1]);
        G[c1][c2] = G[c2][c1];
        cost[c1][c2] = cost[c2][c1];
    }
    Dijkstra(st);
    DFS(ed);
    for(int i = path.size() - 1; i >= 0; i--){
        cout << path[i] << " ";
    }
    cout << d[ed] << " " << miniCost << "\n";
    return 0;
}