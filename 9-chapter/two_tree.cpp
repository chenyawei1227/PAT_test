#include <cstdio>
#include <queue>
using namespace std;

//二叉树结构体
struct node{
    int data;
    node* lchild;
    node* rchild;
};
//新建结点
node* newNode(int v){
    node* Node = new node;
    Node->data = v;
    Node->lchild = Node->rchild = NULL;
    return Node;
}
//查找结点
void search(node* root,int x,int newdata){
    if(root == NULL){
        return;
    }
    if(root->data == x){
        root->data = newdata;
    }
    search(root->lchild, x, newdata);
    search(root->rchild, x, newdata);
}
//插入结点
void insert(node* &root,int x){
    if(root == NULL){
        root = newNode(x);
        return;
    }
    // if(由二叉树的性质，x应该插在左子树){
    //     insert(root->lchild,x);
    // }else{
    //     insert(root->rchild,x);
    // }
}
//创建二叉树保存数据
node* Create(int data[], int n){
    node* root = NULL;
    for(int i = 0; i < n; i++){
        insert(root,data[i]);
    }
    return root;
}
//先序遍历
void preorder(node* root){
    if(root == NULL){
        return;
    }
    printf("%d\n",root->data);
    preorder(root->lchild);
    preorder(root->rchild);
}
//中序遍历
void inorder(node* root){
    if(root == NULL){
        return;
    }
    inorder(root->lchild);
    printf("%d\n",root->data);
    inorder(root->rchild);
}
//后序遍历
void postorder(node* root){
    if(root == NULL){
        return;
    }
    postorder(root->lchild);
    postorder(root->rchild);
    printf("%d\n",root->data);

}
//层次遍历
void LayerOrder(node* root){
    queue<node*> q;
    q.push(root);
    while(!q.empty()){
        node* now = q.front();
        q.pop();
        printf("%d",now->data);
        if(now->lchild != NULL){
            q.push(now->lchild);
        }
        if(now->rchild != NULL){
            q.push(now->rchild);
        }
    }
}

int main(){

    return 0;
}