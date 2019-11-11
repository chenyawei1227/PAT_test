#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

int main(){
    string str1,str2;
    cin>>str1>>str2;
    cout<<str1<<str2<< "\n";

    printf("%s%s\n",str1.c_str(),str2.c_str());
    return 0;
}