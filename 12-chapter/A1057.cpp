#include <cstdio>
#include <cstring>
#include <stack>
#include <queue>
using namespace std;

const int maxn = 100010;
const int sqrN = 316;

stack<int> st;
int block[sqrN];    //记录每一块中存在的元素个数
int table[maxn];    //hash数组，记录元素当前存在的个数
queue<int> qu;
void peekMedian(int k){
    int sum = 0; //存放当前累计存放的数的个数
    int idx = 0; //块号
    while(sum + block[idx] < k){
        sum += block[idx++];
    }
    int num = idx * sqrN; //块号的第一个数
    while(sum + table[num] < k){
        sum += table[num++];
    }
    //printf("%d\n",num); //sum达到k,找到第k大的数为num
    qu.push(num);
}

void Push(int x){
    st.push(x);
    block[x / sqrN]++;
    table[x]++;
    //qu.push(x);
}

void Pop(){
    int x = st.top();   //获得栈顶元素
    st.pop();
    block[x / sqrN]--;
    table[x]--;
    //printf("%d\n",x); //输出x
    qu.push(x);
}

int main(){
    int x, query;
    memset(block, 0, sizeof(block));
    memset(table, 0, sizeof(table));
    char cmd[20];
    scanf("%d",&query);
    for(int i = 0; i < query; i++){
        scanf("%s",cmd);
        if(strcmp(cmd, "Push") == 0){
            scanf("%d",&x);
            Push(x);
        }else if(strcmp(cmd, "Pop") == 0){
            if(st.empty() == true){
                //printf("Invalid\n");
                qu.push(-1);
            }else{
                Pop(); //出栈
            }
        }else if(strcmp(cmd, "PeekMedian") == 0){  //peekMedian
            if(st.empty() == true){
                //printf("Invelid\n");
                qu.push(-1);
            }else{
                int k = st.size();
                if(k % 2 == 1){
                    k = (k + 1) / 2;
                }else{
                    k = k / 2;
                }
                peekMedian(k);
            }
        }
    }
    while(qu.empty() != true){
        if(qu.front() == -1){
            printf("Invalid\n");
        }else{
            printf("%d\n",qu.front());
        }
        qu.pop();
    }
    return 0;
}