/*
* @Author: chenyawei
* @Date:   2019-10-13 15:31:26
* @Last Modified by:   chenyawei
* @Last Modified time: 2019-10-13 15:49:35
*/
#include <cstdio>
#include <cstring>

const int maxn = 256;

bool judge(char str[]){
	int len = strlen(str);
	for(int i = 0; i < len; i++){
		if (str[i] != str[len - 1 - i]){
			return false;
		}
	}
	return true;
}

int main(){
	char str[maxn];

	while(gets(str)){
		if (judge(str)){
			printf("YES\n");
		}else{
			printf("NO\n");
		}
	}

	return 0;
}