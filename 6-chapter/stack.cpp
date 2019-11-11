#include <cstdio>
#include <stack>
#include <iostream>

using namespace std;

int main(){
    stack<int> sta;
    sta.push(1);
    sta.push(2);
    sta.push(3);
    
    cout << sta.top() << ' ' << sta.size();

    sta.pop();

    cout << sta.top() << ' ' << sta.size();
    return 0;
}