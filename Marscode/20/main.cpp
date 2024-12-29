// 比赛配对问题
#include <iostream>
using namespace std;

int solution(int n) {
    // PLEASE DO NOT MODIFY THE FUNCTION SIGNATURE
    // write code here
    int res = 0;
    while(n>1){
        res += (n / 2);
        if(n&1){
            n = (1 + n / 2);
        }else{
            n = (n / 2);
        }
    }
    return res;
}

int main() {
    cout << (solution(7) == 6) << endl;
    cout << (solution(14) == 13) << endl;
    cout << (solution(1) == 0) << endl;

    return 0;
}