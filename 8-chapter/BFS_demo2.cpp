#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;

struct NODE{
    int x,y;
    int step;
}S,T,node;

const int maxn = 100;
int n,m;
char matrix[maxn][maxn];
bool inq[maxn][maxn] = {false};
int X[4] = {0,0,1,-1};
int Y[4] = {1,-1,0,0};

bool test(int x,int y){
    if(x >= n || x < 0 || y >= m || y < 0) return false;
    if(matrix[x][y] == '*') return false;
    if(inq[x][y] == true) return false;
    return true;
}

int BFS(){
    queue<NODE> Q;
    Q.push(S);
    while(!Q.empty()){
        NODE top = Q.front();
        Q.pop();
        if(top.x == T.x && top.y == T.y){
            return top.step;
        }
        for(int i = 0; i < 4; i++){
           int newX = top.x + X[i];
           int newY = top.y + Y[i];
           if(test(newX,newY)){
               node.x = newX,node.y = newY;
               node.step = top.step + 1;
               Q.push(node);
               inq[newX][newY] = true;
           }
        }
    }
    return -1;
}

int main(){
    scanf("%d%d",&n,&m);
    for(int i = 0; i < n; i++){
        getchar();//过滤掉每行后面掉换行符
        for(int j = 0; j < m; j++){
            matrix[i][j] = getchar();
        }
        matrix[i][m + 1] = '\0';
    }

    scanf("%d%d%d%d",&S.x,&S.y,&T.x,&T.y);
    printf("%d",BFS());
    return 0;
}