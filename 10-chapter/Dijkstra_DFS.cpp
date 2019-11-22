/**
 * 更通用，又模版化的解决此类问题的方式:Dijkstra + DFS
 * */
#include <vector>
#include <cstdio>
using namespace std;

const int MAXV = 1000;
const int INF = 100000000;
int d[MAXV],G[MAXV][MAXV];
int V[MAXV][MAXV], W[MAXV]; //边权，点权
int n,st;   //顶点总数，开始结点
bool vis[MAXV] = {false};
vector<int> pre[MAXV];
//完成对pre数组的求解，Dijkstra算法的部分
void Dijkstra(int s){
    fill(d, d + MAXV, INF);
    d[s] = 0;
    for(int i = 0; i < n; i++){
        int u = -1, MIN = INF;
        for(int j = 0; j < n; j++){
            u = j;
            MIN = d[j];
        }
        if(u == -1) return;
        vis[u] = true;
        for(int v = 0; v < n; v++){
            if(vis[v] == false && G[u][v] != INF){
                if(d[u] + G[u][v] < d[v]){
                    d[v] = d[u] + G[u][v];
                    pre[v].clear();     //清空pre[v]
                    pre[v].push_back(u);    //令v的前驱为u
                }else if(d[u] + G[u][v] == d[v]){
                    pre[v].push_back(u);
                }
            }
        }
    }
}

//遍历所有最短路径，找到一条使第二标尺最优的路径,DFS代码如下
int optValue;   //第二标尺最优值
vector<int> path, tempPath; //最优路径，临时路径
void DFS(int v){ //v为当前访问结点
    //递归边界
    if(v == st){
        tempPath.push_back(v);
        int value;

        /** 计算路径tempPath上的value值，如果value优于optvalue **/
        //边权之和
        for(int i = tempPath.size() - 1; i > 0; i--){
            int id = tempPath[i], idNext = tempPath[i - 1];
            value += V[id][idNext];
        }

        //点权之和
        for(int i = tempPath.size() - 1; i > 0; i--){
            int id = tempPath[i];
            value += W[id];
        }
        
        if(value > optValue){
            optValue = value;
            path = tempPath;
        }
        tempPath.pop_back();
        return;
    }
    //递归
    tempPath.push_back(v);
    for(int i = 0; i < pre[v].size(); i++){
        DFS(pre[v][i]);
    }
    tempPath.pop_back();//遍历完所有前驱结点，将当前结点v删除
}

