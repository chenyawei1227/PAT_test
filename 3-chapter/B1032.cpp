/*
* @Author: chenyawei
* @Date:   2019-10-11 10:00:01
* @Last Modified by:   chenyawei
* @Last Modified time: 2019-10-11 10:26:52
*/
#include <cstdio>

int main(){
	const int maxn = 100000;

	int school[maxn] =  {0};
	int n,schoolID,score;
	scanf("%d",&n);

	for(int i=0; i<n; i++){
		scanf("%d %d",&schoolID,&score);
		school[schoolID] += score;
	}

	int max = -1;
	int id = 1;
	for(int j = 1; j<=n; j++){
		if(school[j] > max){
			max = school[j];
			id = j;
		}
	}

	printf("%d %d\n", id,max);
	return 0;
}