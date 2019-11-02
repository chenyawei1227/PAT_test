/*
* @Author: chenyawei
* @Date:   2019-11-01 23:25:09
* @Last Modified by:   chenyawei
* @Last Modified time: 2019-11-02 13:34:28
*/
#include<cstdio>
#include<iostream>
using namespace std;

template <class T>
//通过sizeof(array)获取整个数组所占的内存字节数，
//再通过sizeof(*array)或者sizeof(array[0])或者sizeof(int)来获取单个元素所占的字节数，
//用整个数组所占空间除一个元素所占得空间，结果肯定就是数组元素的个数
int getArrayLen(T&array)
{
    return sizeof(array) / sizeof(array[0]);
}
int main()
{
    int list[] = {1,2,3,4,6,5,7,8,9,0};
    int length = getArrayLen(list);
    printf("%d\n", length);
    return 0;
}