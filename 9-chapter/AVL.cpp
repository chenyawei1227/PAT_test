#include <cstdio>
#include <algorithm>
using namespace std;

/*
结点的定义
*/
struct node{
    int data,v,height;   //v为结点权值，height为当前子树的高度
    node *lchild,*rchild;   //左右孩子结点地址
};

/*
生成一个新结点，v为结点的权值
*/
node* newNode(int v){
    node* Node = new node;
    Node->v = v;
    Node->height = 1;
    Node->lchild = Node->rchild = NULL;
    return Node;
}

/*
获取以root为跟结点的子树的当前height
*/
int getHeight(node* root){
    if(root == NULL) return 0;
    return root->height;
}

/*
计算结点root的平衡因子
*/
int getBalanceFactor(node* root){
    return getHeight(root->lchild) - getHeight(root->rchild);
}

/*
更新结点root的height
*/
void updateHeight(node* root){
    
    root->height = max(getHeight(root->lchild),getHeight(root->rchild)) + 1;
}

/*
查找AVL树中数据域为x的结点
*/
void search(node* root, int x){
    if(root == NULL){
        printf("search failed\n");
        return;
    }
    if(x == root->data){    //查找成功，访问之
        printf("%d\n",root->data);
    }else if(x < root->data){
        search(root->lchild,x);
    }else{
        search(root->rchild,x);
    }
}

/*
左旋（left rotation)
*/
void L(node* &root){
    node* temp = root->rchild;
    root->rchild = temp->lchild;
    temp->lchild = root;
    updateHeight(root);
    updateHeight(temp);
    root = temp;
}

/*
右旋（right rotation)
*/
void R(node* &root){
    node* temp = root->lchild;
    root->lchild = temp->rchild;
    temp->rchild = root;
    updateHeight(root);
    updateHeight(temp);
    root = temp;
}

/*
在AVL树中插入权值为v的结点
*/
void insert(node* &root, int v){
    if(root == NULL){
        root = newNode(v);
        return;
    }
    if(v < root->v){
        insert(root->lchild,v);
        updateHeight(root);
        if(getBalanceFactor(root) == 2){
            if(getBalanceFactor(root->rchild) == 1){
                R(root);
            }else if(getBalanceFactor(root->lchild) == -1){
                L(root->lchild);
                R(root);
            }
        }
    }else{
        insert(root->rchild,v);
        updateHeight(root);
        if(getBalanceFactor(root) == -2){
            if(getBalanceFactor(root) == 1){
                L(root);
            }else if(getBalanceFactor(root) == -1){
                R(root->rchild);
                L(root);
            }
        }
    }
}

/*
创建AVL树
*/
node* Create(int data[], int n){
    node* root = NULL;
    for(int i = 0; i < n; i++){
        insert(root, data[i]);
    }
    return root;
}