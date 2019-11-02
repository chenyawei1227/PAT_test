/*
* @Author: chenyawei
* @Date:   2019-11-01 23:26:41
* @Last Modified by:   chenyawei
* @Last Modified time: 2019-11-02 00:05:59
*/
#include<cstdio>
#include<iostream>
using namespace std;

#define GET_LEN(array, len) { len = sizeof(array)/sizeof(array[0]);}

int main()
{
    int list[] = {1,2,3,4,5,6,7,8,9,0};
    int length;
    GET_LEN(list, length);
    printf("%d\n", length);
	printf("%s\n", "----------------------------");
    for (int i = 0; i < length; ++i)
    {
    	printf("%d\n", list[i]);
    }
    return 0;
}