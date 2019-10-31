/*
* @Author: chenyawei
* @Date:   2019-10-13 16:02:42
* @Last Modified by:   chenyawei
* @Last Modified time: 2019-10-13 17:25:23
*/
#include <cstdio>
#include <cstring>

int  main() {

	char str[90];
	gets(str);

	int len = strlen(str),r = 0,h = 0;
	char ans[90][90];

	for(int i = 0; i < len; i++){
		if(str[i] != ' '){
			ans[r][h++] = str[i];
		}else{
			ans[r][h] = '\0'; //末尾是结束符 意思是告诉编译器，这不是字符0，而是空字符 空字符\0对应的二进制为00000000，而数字0为00110000
			r++;
			h = 0;
		}
	}
	ans[r][h] = '\0'; //末尾是结束符 意思是告诉编译器，这不是字符0，而是空字符空字符\0对应的二进制为00000000，而数字0为00110000


	for (int i = r; i >= 0; i--)
	{
		printf("%s", ans[i]);
		if(r > 0){
			printf(" ");
		}
	}

	return 0;
}

/**
int main(){

	int num = 0;
	char str[90][90];

	while(scanf("%s",str[num]) != EOF){
		num ++;
	}

	for(int i = num -1; i >= 0; i--){
		printf("%s", str[i]);
		if(i>0){
			printf(" ");
		}
	}
	return 0;
}
*/