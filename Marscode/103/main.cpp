// 完美整数
#include <iostream>
using namespace std;

int solution(int x, int y) {
    // Edit your code here
    auto perfect=[](int num){
        int n = num % 10;
        num /= 10;
        while(num > 0){
            if(num%10 == n){
                num /= 10;
            }else{
                return false;
            }
        }
        return true;
    };
    int res = 0;
    for(int i = x; i <= y; ++i){
        if(perfect(i)){
            ++res;
        }
    }
    return res;
}

int main() {
    // Add your test cases here

    std::cout << (solution(1, 10) == 9) << std::endl;
    std::cout << (solution(2, 22) == 10) << std::endl;

    return 0;
}