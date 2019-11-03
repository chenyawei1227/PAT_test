/*
* @Author: chenyawei
* @Date:   2019-11-02 13:21:03
* @Last Modified by:   chenyawei
* @Last Modified time: 2019-11-02 17:23:46
*/
#include <cstdio>
#include <algorithm>

template <class T>
int getArrayLen(T&array){
	return sizeof(array) / sizeof(array[0]);
}

void insertSort(int A[],int n){
	for(int i = 1; i<= n; i++){
		int temp = A[i], j = i;
		while(j>0 && temp < A[j - 1]){
			A[j] = A[j - 1];
			j--;
		}
		A[j] = temp;
	}
}

int main(){
	int A[] = {6,3,5,2,1,4};
	int n = getArrayLen(A);
	insertSort(A,n);
	for(int i = 0; i < n; i++){
		printf("%d\n",A[i]);
	}
	return 0;
}