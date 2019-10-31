/*
* @Author: chenyawei
* @Date:   2019-10-12 23:09:02
* @Last Modified by:   chenyawei
* @Last Modified time: 2019-10-13 15:56:06
*/
#include <cstdio>
	//13行2列数组
int month[13][2] = {
	{0,0},
	{31,31},
	{28,29},
	{31,31},
	{30,30},
	{31,31},
	{30,30},
	{31,31},
	{31,31},
	{30,30},
	{31,31},
	{30,30},
	{31,31}
};

bool isleap(int year){
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int main(){

	int time1, y1, m1, d1;
	int time2, y2, m2, d2;

	while(scanf("%d %d", &time1,&time2) != EOF){

		if(time1 > time2){
			int temp = time2;
			time2 = time1;
			time1 = temp;
		}else if(time1 == time2){
			printf("%d\n", 0);
		}
		y1 = time1 / 10000; m1 = time1 % 10000 / 100; d1 = time1 % 100;
		y2 = time2 / 10000; m2 = time2 % 10000 / 100; d2 = time2 % 100;

		int days = 1;
		for (int i = 0; i < y1 - y2 - 1; ++i){
			if(isleap(y1 + 1)){
				days += 366;
			}else{
				days += 365;
			}
		}

		while(y1 < y2 || m1 < m2 || d1 < d2){
			days++; d1++;
			if(d1 == month[m1][isleap(y1)] ){
				m1++;
				d1 = 1;
			}
			if(m1 == 13){
				y1++;
				m1 = 1;
			}
		}
		printf("%d\n", days);
	}

	return 0;
}





