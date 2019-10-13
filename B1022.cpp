/*
* @Author: chenyawei
* @Date:   2019-10-13 14:34:49
* @Last Modified by:   chenyawei
* @Last Modified time: 2019-10-13 15:29:12
*/
#include <cstdio>

const int maxn = 40;

//十进制数转换为任意进制数
void decadeToD(int sum ,int D){
	int num[maxn];
	int n = 0;

	do{
		//除基求余
		num[n++] = sum % D;
		sum = sum / D;
	}while(sum != 0);
	printf("A+B的D进制数：");
	for (int i = n -1; i >= 0; i--){
		printf("%d",num[i]);
	}
	printf("\n");
	printf("%s\n","-----------------------");
}
//任意进制数转换为十进制数
void DToDecade(int Z,int p){
	int product = 1;
	int decade = 0;
	while(Z != 0){
		decade = decade + (Z % 10) * product;
		product = product * p;
		Z = Z / 10;
	}
	printf("Z转换为十进制数： %d\n", decade);
}

int main(){
	
	int A, B, D, sum;
	scanf("%d %d %d", &A, &B, &D);

	sum = A + B;
	decadeToD(sum,D);

	int Z,p;
	scanf("%d %d", &Z, &p);
	DToDecade(Z,p);

	return 0;


}