#include <queue>

using namespace std;

const int maxn = 2010;
const int INF = 100000000;
int n, G[maxn][maxn];
bool inq[maxn] = {false};

/**
 * 邻接矩阵版
 * */
void BFS(int u){
    queue<int> q;
    q.push(u);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int v = 0; v < n; v++){
            if(inq[v] == false && G[u][v] != INF){
                q.push(v);
                inq[v] = true;
            }
        }
    }
}

//遍历图G
void BFSTrave(){
    for(int u = 0; u < n; u++){
        if(inq[u] == false){
            BFS(u);
        }
    }
}

/**
 * 邻接表版
 * */
vector<int> Adj[maxn];
int n;
bool inq[maxn] = {false};
void BFS2(int u){
    queue<int> q;
    q.push(u);
    inq[u] = true;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int i = 0; i < Adj[u].size(); i++){
            int v = Adj[u][i];
            if(inq[v] != true){
                q.push(v);
                inq[v] = true;
            }
        }
    }
}

//遍历图G
void BFSTrave(){
    for(int u = 0; u < n; u++){
        if(inq[u] == false){
            BFS(u);
        }
    }
}

//需要输出编号和层号
struct Node{
    int v;
    int layer;
};

vector<Node> AdjNode[maxn];
void BFS(int s){
    queue<Node> q;
    Node start;
    start.v = s;
    start.layer = 0;
    q.push(start);
    inq[start.v] = true;
    while(!q.empty()){
        Node topNode = q.front();
        q.pop();
        int u = topNode.v;
        for(int i = 0; i < AdjNode[u].size(); i++){
            Node next = AdjNode[u][i];
            next.layer = topNode.layer + 1;
            if(inq[next.v] == false){
                q.push(next);
                inq[next.v] = true;
            }
        }
    }
}