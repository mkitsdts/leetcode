// 数字字符串格式化
#include <string>
#include <iostream>

std::string solution(const std::string& s) {
    // PLEASE DO NOT MODIFY THE FUNCTION SIGNATURE
    // write code here
    size_t begin = 0;
    size_t end = s.size() - 1;
    while(s[begin]=='0'){
        ++begin;
    }
    while(s[end]!='.'){
        --end;
        if(end==begin){
            end = s.size();
            break;
        }
    }
    if(end-begin<=3){
        std::cout<<"s.substr: "<<s.substr(begin)<<std::endl;
        return std::string{s.substr(begin)};
    }
    size_t curr = (end - begin) % 3;
    if(curr==0){
        curr=3;
    }
    std::string res{s.substr(begin,curr)};
    while(curr < (end-begin)){
        res+=(","+s.substr(begin+curr,3));
        curr+=3;
    }
    res+=s.substr(end);
    std::cout<<"res = "<<res<<std::endl;
    std::cout<<"begin = "<<begin<<std::endl;
    std::cout<<"end = "<<end<<std::endl;
    std::cout<<"s[end] = "<<s.substr(end)<<std::endl;
    return res;
}

int main() {
    std::cout << (solution("1294512.12412") == "1,294,512.12412") << std::endl;
    std::cout << (solution("0000123456789.99") == "123,456,789.99") << std::endl;
    std::cout << (solution("987654321") == "987,654,321") << std::endl;
    return 0;
}