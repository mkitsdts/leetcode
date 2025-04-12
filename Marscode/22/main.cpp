// 最少字符串操作次数

#include <iostream>
#include <string>
using namespace std;

int solution(const std::string& S) {
    // PLEASE DO NOT MODIFY THE FUNCTION SIGNATURE
    // write code here
    int res = 0;
    int count = 0;
    int num[26] = {0};
    for(auto i : S){
        ++num[i - 'a'];
        if(num[i - 'a'] == 2){
            ++res;
            ++count;
            num[i - 'a'] = 0;
        }
    }
    int odd_size = 0;
    for(size_t i = 0; i < 26; ++i){
        if(num[i]&1){
            ++odd_size;
        }
    }
    if(count+odd_size <= 26){
        return res;
    }

    if(odd_size > count){
        return res;
    }else{
        return (count-odd_size)&1?res+1:res;
    }
    return -1;
}

int main() {
    std::cout << (solution("abab") == 2) << std::endl;
    std::cout << (solution("aaaa") == 2) << std::endl;
    std::cout << (solution("abcabc") == 3) << std::endl;
}