#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cmath>  
#include <algorithm>

using namespace std;

int main(){
    srand((unsigned)time(NULL));
    //输出[a,b]的随机数公式：rand()%(b-a+1)+a
    for(int i = 0; i < 10; i++){
        printf("%d\n", rand());
    }
    printf("%s\n","=================");
    for(int i = 0; i < 10; i++){
        printf("%d\n",rand() % 11); //[0,10]
    }
    printf("%s\n","=================");
    for(int i = 0; i < 10; i++){
        printf("%d\n",rand() % 5 + 3); //[3,7]
    }
    //当输出的随机数大于RAND_MAX时，上面的方法就不能用了。
    //可以用 : (int)(round(1.0*rand()/RAND_MAX*(b-a)+a))   
    for(int i = 0; i < 10; i++){
        printf("%d ",(int)(round(1.0*rand()/RAND_MAX*50000 + 10000)));
    }
    return 0;
}