#include <cstdio>
#include <queue>

using namespace std;

struct node{
    char data;
    node* lchild;
    node* rchild;
};
char pre[] = {'A','B','D','E','C','F'};
char in[] = {'D','B','E','A','C','F'};



node* create(int preL, int preR, int inL, int inR){
    if(preL > preR) {
        return NULL;
    }
    node* root = new node;
    root->data = pre[preL];
    int k;
    for(k = inL; k <= inR; k++){
        if(in[k] == pre[preL]){
            break;
        }
    }
    int numLeft = k - inL;
    root->lchild = create(preL + 1, preL + numLeft, inL, k -1);
    root->rchild = create(preL + numLeft + 1, preR, k + 1, inR);
    return root;
}

//先序遍历
void preorder(node* root){
    if(root == NULL){
       // printf("root is NULL.");
        return;
    }
    printf("%c ",root->data);
    preorder(root->lchild);
    preorder(root->rchild);
}

//层次遍历
void LayerOrder(node* root){
    queue<node*> q;
    q.push(root);
    while(!q.empty()){
        node* now = q.front();
        q.pop();
        printf("%c ",now->data);
        if(now->lchild != NULL){
            q.push(now->lchild);
        }
        if(now->rchild != NULL){
            q.push(now->rchild);
        }
    }
}

int main(){
    node* now = create(0,5,0,5);
    preorder(now);
    printf("\n------------\n");
    LayerOrder(now);
    return 0;
}