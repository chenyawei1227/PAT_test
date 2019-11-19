#include <cstdio>
#include <vector>
using namespace std;



int main(){
    vector<int> vi;
    for(int i = 1; i <= 5; i++){
        vi.push_back(i);
    }
    vi.pop_back(); //删除vi的尾部元素
    vector<int>::iterator it = vi.begin();
    for(int i = 0; i < 5; i++){
        printf("%d ",*(it + i));    //输出vi[i]
    }
    printf("\n");
    for(int i = 0; i < vi.size(); i++){
        printf("%d ",*(it + i));    //输出vi[i]
    }
    printf("\n");
    for(vector<int>::iterator it = vi.begin(); it != vi.end(); it++){
        printf("%d ",*it);
    }
    printf("\n");

    vector<vector<int> > graph;
    graph[0][0]=1;
    graph[0][1]=2;
    graph[1][0]=3;
    graph[1][1]=4;
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            printf("%d ",graph[i][j]);
        }
    }
    return 0;
}