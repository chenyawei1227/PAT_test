#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 100010;
struct NODE{
    int address;
    int data;
    int next;
    bool falg;//是否在当前链表上
}node[maxn];

bool cmp(NODE a,NODE b){
    if(a.falg == false || b.falg == false){
        return a.falg > b.falg;//只要a和b中有一个无效节点，就把他们放到后面
    }else{
        return a.data < b.data;
    }
    //  return a.data < b.data;
}

int main(){
    for(int i = 0; i < maxn; i++){
        node[i].falg = false;
    }
    int n,begin,address,data,next;
    scanf("%d%d",&n,&begin);
    for(int i = 0; i < n; i++){
        scanf("%d%d%d",&address,&data,&next);
        node[address].data = data;
        node[address].next = next;
        node[address].address = address;
    }
    int count = 0, p = begin;
    while(p != -1){
        node[p].falg = true;
        count++;
        p = node[p].next;
    }
    if(count == 0){
        printf("0 -1\n");
    }else{
        sort(node,node + maxn,cmp);
        printf("%d %05d\n",count,node[0].address);
        for(int i = 0; i < count; i++){
            if(i != count -1){
                printf("%05d %5d %05d\n",node[i].address,node[i].data,node[i + 1].address);
            }else{
                printf("%05d %5d -1\n",node[i].address,node[i].data);
            }  
        }
    }
    return 0;
}
