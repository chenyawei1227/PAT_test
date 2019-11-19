#include <cstdio>
#include <vector>
using namespace std;

const int maxv = 1000;  //最大顶点树
const int inf = 1000000000; //设置inf为一个很大的数

/**
 * 邻接矩阵版
 * */
int n, G[maxv][maxv];
bool vis[maxv] = {false};

void DFS(int u, int depth){
    vis[u] = true;
    for(int v = 0; v < n; v++){
        if(vis[u] == false && G[u][v] != inf){
            DFS(v, depth + 1);
        }
    }
}

void DFSTrave(){    //遍历图G
    for(int u = 0; u < n; u++){
        if(vis[u] == false){
            DFS(u,1);
        }
    }
}

/**
 * 邻接表版
 * */
vector<int> Adj[maxv];
int n;
bool vis[maxv] = {false};

void DFS(int u, int depth){
    vis[u] = true;
    for(int i = 0; i < Adj[u].size(); i++){
        int v = Adj[u][i];
        if(vis[u] == false){
            DFS(v, depth + 1);
        }
    }
}

void DFSTrave(){
    for(int u = 0; u < n; u++){
        if(vis[u] == false){
            DFS(u,1);
        }
    }
}