/*
* @Author: chenyawei
* @Date:   2019-10-12 22:33:35
* @Last Modified by:   chenyawei
* @Last Modified time: 2019-10-12 23:02:28
*/
#include <cstdio>

int main(){

	int row,col;
	char c;

	scanf("%d %c",&col,&c);
	if(col % 2 == 1){
		row = col / 2 + 1;
	}else{
		row = col / 2;
	}
	for(int i = 0; i<col; i++){
		printf("%c",c);
	}

	printf("\n");

	for(int i = 2; i< row; i++){
		printf("%c", c);
		for (int i = 0; i < col -2; ++i){
			printf(" ");
		}
		printf("%c\n", c);
	}

	for(int i = 0; i<col; i++){
		printf("%c", c);
	}

	printf("\n");
	return 0;
}