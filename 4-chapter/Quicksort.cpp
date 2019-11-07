#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <cmath>
using namespace std;

int partition(int A[], int left, int right){

    int temp = A[left];
    while(left < right){
        while(left < right && A[right] > temp) right--;
        A[left] = A[right];
        while(left < right && A[left] <= temp ) left++;
        A[right] = A[left];
    }
    A[left] = temp;
    return left;
}

//优化主原没有把区间[left,right]分成两个近似的子区间:随机的选择主原
int randPartition(int A[], int left, int right){
    int randNum = (round(1.0*rand()/RAND_MAX*(right - left) + left));
    printf("randNum: %d\n",randNum);
    swap(A[randNum],A[left]);
    int temp = A[left];
    while(left < right){
        while(left < right && A[right] > temp) right--;
        A[left] = A[right];
        while(left < right && A[left] <= temp) left++;
        A[right] = A[left]; 
    }
    A[left] = temp;
    return left;
}

void quickSort(int A[],int left, int right){
    if(left < right){
        //int pos = partition(A,left,right);
        int pos = randPartition(A,left,right);
        quickSort(A,left,pos - 1);
        quickSort(A,pos + 1,right);
    }
}

int main(){
    int A[] = {35,18,16,72,24,65,12,88,46,28,100,66,866};
    quickSort(A,0,9);
    for(int i = 0; i < 10; i++){
        printf("%d\n",A[i]);
    }
    return 0;
}