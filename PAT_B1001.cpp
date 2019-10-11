/*
* @Author: chenyawei
* @Date:   2019-10-11 09:14:46
* @Last Modified by:   chenyawei
* @Last Modified time: 2019-10-11 09:24:08
*/
#include <cstdio>

int main(){

	int n,temp,sum;

	scanf("%d",n);
	sum = 0;

	while( n != 1){
		temp = n % 2;
		if(temp == 1){
			n = (3 * n + 1)/2;
		}
		if(temp == 0){
			n = n / 2;
		}
		sum ++;
	}
	
}