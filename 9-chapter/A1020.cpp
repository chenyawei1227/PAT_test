#include <cstdio>
#include <queue>

using namespace std;

const int maxn = 50;
struct node{
    node* lchild;
    node* rchild;
    int data;   
};

int n;
int pre[maxn], in[maxn], post[maxn];


node* create(int postL, int postR, int inL, int inR){
    if(postL > postR) return NULL;
    node* root = new node;
    root->data = post[postR];
    int k;
    //下面放了一个严重的错误：k变量之前已经定义过了，for循环中又定义了一次int k = inL；，
    //运行时会报错：bus error错误，总线错误;牢记！！！
    //for(int k = inL; in[k] != post[postR]; k++){}
    for(k = inL; k <= inR; k++){
        if(in[k] == post[postR]){
            break;
        }
    }
    int numLeft = k - inL;
    root->lchild = create(postL, postL + numLeft - 1, inL, k - 1);
    root->rchild = create(postL + numLeft, postR - 1, k + 1, inR);
    return root;
}

int num = 0;
void levelOrder(node* root){
    queue<node*> q;
    q.push(root);
    while(!q.empty()){
        node* now = q.front();
        q.pop();
        printf("%d",now->data);
        num++;
        if(num < n){
            printf(" ");
        }
        if(now->lchild != NULL) q.push(now->lchild);
        if(now->rchild != NULL) q.push(now->rchild);
    }
}

int main(){
    scanf("%d",&n);
    for(int i = 0; i < n; i++){
        scanf("%d",&post[i]);
    }
    for(int i = 0; i < n; i++){
        scanf("%d",&in[i]);
    }
    
    node* root = create(0, n -1, 0, n -1);
    levelOrder(root);
    return 0;
}