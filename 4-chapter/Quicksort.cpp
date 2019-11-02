/*
* @Author: chenyawei
* @Date:   2019-10-19 22:19:52
* @Last Modified by:   chenyawei
* @Last Modified time: 2019-11-02 13:38:45
*
*/
#include <cstdio>

template <class T>
int getArrayLen(T&array)
{
    return sizeof(array) / sizeof(array[0]);
}

/*
只从左端扫描，时间复杂度为O(n2)
 */
void quickSort(int R[],int length){
	int k,temp;
	for (int i = 0; i < length; ++i){
		k = i;
		for (int j = i; j < length; ++j){
			if (R[j] < R[k]){
				k = j;
			}
		}
		temp = R[i];
		R[i] = R[k];
		R[k] = temp;
	}
}

/*
左右两端同时扫描，递归方式，最好情况时间复杂度为O(nlog2n),最坏为O(n2)
 */
void quickSort2(int R[],int low, int high){
	int temp;
	int i = low, j = high;
	if(low < high){
		temp = R[low];
		while(i < j){
			while(j > i && R[j] >= temp){
				--j;	
			} 
			//跳出循环，即R[j] < temp,将R[j]放到temp的左边
			if(i < j){
				R[i] = R[j];
				++i;
			}
			while(i < j && R[i] <= temp){
				++i;
			}	
			//跳出循环，即R[i] > temp,将R[i]放到temp的右边
			if(i < j){
				R[j] = R[i];
				--j;
			}
		}
		R[i] = temp;
		quickSort2(R,low,i-1);//对temp左边关键字排序
		quickSort2(R,i+1,high);//对temp右边关键字排序
	}

}

int main()
{
	int R[] = {11,2,3,44,5,26,73,8,9,0};
    int length = getArrayLen(R);
    quickSort(R,length);
    for (int i = 0; i < length; ++i){
    	printf("%d\n", R[i]);
    }
    printf("%s\n", "===============================");
    int R1[] = {111,20,23,434,53,26,73,8,9,10};
    quickSort2(R1,0,9);
    for (int i = 0; i < length; ++i){
    	printf("%d\n", R1[i]);
    }
	return 0;
}