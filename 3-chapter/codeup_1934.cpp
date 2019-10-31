/*
* @Author: chenyawei
* @Date:   2019-10-12 22:08:59
* @Last Modified by:   chenyawei
* @Last Modified time: 2019-10-12 22:32:38
*/
#include <cstdio>

int main(){

	const int max = 200;
	int n,x;
	int num[max] = {0};

	while(scanf("%d",&n) != EOF){
		for(int i = 0; i < n; i++){
		scanf("%d",&num[i]);
		}
		scanf("%d",&x);

		int j;
		for(j = 0; j < n; j++){
			if(x == num[j]){
				printf("%d\n",j);
				break;
			}
		}
		if(j == n){
			printf("%d\n",-1);
		}
	}
	
	return 0;
}