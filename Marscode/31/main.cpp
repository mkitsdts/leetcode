// 不同整数的计数问题
#include <cstddef>
#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

int solution(string word) {
    // PLEASE DO NOT MODIFY THE FUNCTION SIGNATURE
    // write code here
    unordered_set<int> s;
    for(size_t i = 0; i < word.size(); ++i){
        if(word[i] <= '9' && word[i] >= '0'){
            int num = 0;
            while(true){
                if(word[i+num] <= '9' && word[i+num] >= '0'){
                    ++num;
                }else{
                    auto n = atoi(word.substr(i,num+1).c_str());
                    s.emplace(n);
                    i += num;
                    break;
                }
            }
        }
    }
    return s.size();
}

int main() {
    cout << (solution("a123bc34d8ef34") == 3) << endl;
    cout << (solution("t1234c23456") == 2) << endl;
    cout << (solution("a1b01c001d4") == 2) << endl;
    cout << (solution("zgw5f0k7rj4q4tsk4dos1u") == 5) << endl;
    return 0;
}