/*二分查找*/
#include <cstdio>

int binarysearch(int A[], int left, int right, int x){
    int mid;
    while(left <= right){
        mid = (left + right) / 2;
        if(A[mid] == x){
            return mid;
        }else if(A[mid] > x){
            right = mid -1;
        }else{
            left = mid + 1;
        }
    }
    return -1;
}

int main(){
    const int n = 10;
    int A[n] = {1,3,4,6,7,8,34,232,644,3433};
    printf("%d %d\n",binarysearch(A,0,n-1,6),binarysearch(A,0,n-1,9));
    return 0;
}