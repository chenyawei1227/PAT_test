#include <cstdio>
#include <stack>
#include <queue>
#include <map>
#include <string>
#include <iostream>
using namespace std;

struct node{
    double num; //数字符
    char op;  //操作符
    bool flag;//true表示时数字符，false表示是操作符
};

string str; 
stack<node> s;//放置操作符
queue<node> q;//放置后序表达式
map<char,int> op;

//中序转后序
void midToBackOrder(){
    double num;
    node temp;
    for(int i = 0; i < str.length(); i++){
        if(str[i] >= '0' && str[i] <= '9'){
            temp.num = str[i] - '0';
            while(i < str.length() && str[i] >= '0' && str[i] <= '9'){
                temp.num = temp.num * 10 + (str[i] - '0');
                i++;
            }
            temp.flag = true;
            q.push(temp);
        }else{
            temp.flag = false;
            while(!s.empty() && op[str[i]] <= op[s.top().op]){
                q.push(s.top());
                s.pop();
            }
            temp.op = str[i];
            s.push(temp);
            i++;
        }
    }
    while(!s.empty()){
        q.push(s.top());
        s.pop();
    }
}

//计算存储在栈中的后序表达式
double Col(){
    node cur,temp;
    double temp1,temp2;
    while(!q.empty()){
        cur = q.front();
        q.pop();
        if(cur.flag == true) s.push(cur);
        else{
            temp2 = s.top().num;
            s.pop();
            temp1 = s.top().num;
            s.pop();
            temp.flag = true;
            if(cur.op == '+') temp.num = temp1 + temp2;
            else if(cur.op == '-') temp.num = temp1 - temp2;
            else if(cur.op == '*') temp.num = temp1 * temp2;
            else temp.num = temp1 / temp2;
            s.push(temp);
        }
    }
    return s.top().num;
}

int main(){ 
    op['+'] = op['-'] = 1;
    op['*'] = op['/'] = 2;
    while(getline(cin,str), str != "0"){
        for(string::iterator it = str.end(); it != str.begin(); it--){
            if(*it == ' ' ) str.erase(it);
        }
        while(!s.empty()) s.pop();
        midToBackOrder();
        printf("%.2f\n",Col());
    }
    return 0;
}