/*
* @Author: chenyawei
* @Date:   2019-11-02 22:23:42
* @Last Modified by:   chenyawei
* @Last Modified time: 2019-11-03 13:54:33
*/
#include <cstdio>
#include <set>

using namespace std;

int main(){

	set <int> st;
	st.insert(0);
	st.insert(1);
	st.insert(2);
	st.insert(3);
	for(set<int>::iterator it = st.begin(); it != st.end(); it++){
		printf("%d\n",*it);
	}
	printf("%s\n", "----------------");

	//st.erase(2);
	st.erase(st.find(2));
	for(set<int>::iterator it = st.begin(); it != st.end(); it++){
		printf("%d\n",*it);
	}
	return 0;
}

