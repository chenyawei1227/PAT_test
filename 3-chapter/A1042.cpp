#include <cstdio>
#include <map>
#include <string>
#include <iostream>
using namespace std;

// int main(){
//     map<int,string> staC, midC;
//     int m[55]; //数组长度一定要略大于数组的实际数据长度
//     int n;
//     scanf("%d",&n);
//     for(int i = 1; i <= 54; i++){
//         scanf("%d",&m[i]);
//     }
//     for(int i = 1; i <= 52; i++){
//         string str;
//         if((i / 14) < 1){
//             str = "S" + to_string(i);
//         }else if(1 <= (i / 14) && (i / 27) < 1){
//             if(i % 13 == 0){
//                 str = "H" + to_string(13);
//             }else{
//                 str = "H" + to_string(i % 13);
//             }
//         }else if(1 <= (i / 27) && (i / 40) < 1){
//             if(i % 13 == 0){
//                 str = "C" + to_string(13);
//             }else{
//                 str = "C" + to_string(i % 13);
//             }
//         }else if(1 <= (i / 40) && (i / 53) < 1){
//             if(i % 13 == 0){
//                 str = "D" + to_string(13);
//             }else{
//                 str = "D" + to_string(i % 13);
//             }
//         }       
//         staC[i] = str;
//     }
//     staC[53] = "J1";
//     staC[54] = "J2";

//     int temp = 0;
//     while(n > 0){
//         if(temp == 0){
//             for(int i = 1; i <= 54; i++){
//                 midC[m[i]] = staC[i];
//             }
//             temp = 1;
//         }else{
//             for(int i = 1; i <= 54; i++){
//                 staC[m[i]] = midC[i];
//             }
//             temp = 0;  
//         } 
//         n--;
//     }
//     for(int i = 1; i <= 54; i++){
//         if(temp == 1){
//             cout << midC[i];
//         }else{
//             cout << staC[i];
//         }
//         if (i < 54)
//         {
//             printf(" ");
//         }  
//     }
//     return 0;
// }

const int N = 54;
const char m[5] = {'S','H','C','D','J'};
int main(){
    int k;
    int start[N + 1],end[N + 1], next[N + 1];
    scanf("%d",&k);
    for(int i = 1; i <= N; i++){
        start[i] = i;
    }
    for(int i = 1; i<=N; i++){
        scanf("%d",&next[i]);
    }
    for(int step = 0; step < k; step++){
        for(int i = 1; i<=N; i++){
            end[next[i]] = start[i];
        }
        for(int j = 1; j<=N; j++){
            start[j] = end[j];
        }
    }
    for(int i = 1; i <= N; i++){
        if(i != 1) printf(" ");
        start[i]--;
        printf("%c%d",m[start[i] / 13],start[i] % 13 + 1);
        //if(i <N) printf(" ");
    }
    return 0;
}
