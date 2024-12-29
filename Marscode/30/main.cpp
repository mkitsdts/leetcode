// 组成字符串ku的最大次数
#include <iostream>
#include <string>

using namespace std;

int solution(const string& s) {
    // PLEASE DO NOT MODIFY THE FUNCTION SIGNATURE
    // write code here
    int k = 0,u = 0;
    for(auto& i:s){
        if(i =='k'||i == 'K'){
            ++k;
        }else if(i =='u'||i == 'U'){
            ++u;
        }
    }
    return k>u?u:k;
}

int main() {
    cout << (solution("AUBTMKAxfuu") == 1) << endl;
    cout << (solution("KKuuUuUuKKKKkkkkKK") == 6) << endl;
    cout << (solution("abcdefgh") == 0) << endl;
}