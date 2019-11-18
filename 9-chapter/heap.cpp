#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 100;
int heap[maxn], n = 10;

/**
 * 每次调整都是把结点从上往下的调整，向下调整
 **/
void downAdjust(int low, int high){
    int i = low, j = i * 2;//i为欲调整结点，j为其左孩子结点
    while(j < high){
        if(j + 1 <= high && heap[j + 1] > heap[j]){
            j = j + 1;  //让j指向其右孩子
        }
        if(heap[j] > heap[i]){
            swap(heap[j], heap[i]);
            i = j;
            j = i * 2;
        }else{
            break;
        }
    }
}

/**
 * 建堆,堆为完全二叉树，其叶子结点堆个数（n/2 向上取整）
 * 数组下标从1到（n/2 向下取整）范围内的结点都是非叶子结点
 * */
void createHeap(){
    for(int i = n / 2; i >= 1; i--){    //倒着枚举结点
        downAdjust(i, n);
    }
}

/* 
 * 删除堆顶元素
 * 最后一个元素覆盖堆顶元素，然后对根结点进行调整
 **/
void deleteTop(){
    heap[1] = heap[n--];
    downAdjust(1,n);
}

/**
 * 向上调整
 * 当想往堆里面添加一个元素，可以把要添加堆元素放到最后，
 * 然后向上调整
 * */
void upAdjust(int low, int high){
    int i = high, j = i / 2;
    while(j >= low){
        if(heap[j] < heap[i]){
            swap(heap[j], heap[i]);
            i = j;
            j = i / 2;
        }else{
            break;
        }
    }
}

/**
 * 添加元素x
 * */
void insert(int x){
    heap[++n] = x;
    upAdjust(1,n);
}

/**
 * 堆排序
 * */
void heapSort(){
    createHeap();
    for(int i = n; i > 1; i--){
        swap(heap[i],heap[1]);
        downAdjust(1,n -1);
    }
}
