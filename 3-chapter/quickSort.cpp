/*
* @Author: chenyawei
* @Date:   2019-10-19 22:19:52
* @Last Modified by:   chenyawei
* @Last Modified time: 2019-10-19 22:26:58
*/

void quickSort(int num[i]){
	int k,temp;
	for (int i = 1; i <= n; ++i)
	{
		k = i;
		for (int j = i; j <= n; ++j)
		{
			if (num[j] < num[k])
			{
				k = j;
			}
		}
		temp = num[i];
		num[i] = num[k];
		num[k] = temp;
	}
}