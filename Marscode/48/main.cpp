// aÌæ»»º¯Êý
#include <iostream>
#include <string>
#include <vector>

std::string solution(const std::string& s) {
    // PLEASE DO NOT MODIFY THE FUNCTION SIGNATURE
    // write code here
    std::vector<int> index;
    index.push_back(0);
    for(auto i = 0; i < s.size(); ++i){
        if(s[i]=='a'){
            index.push_back(i);
        }
    }
    
    if(index.size() <= 1){
        return {};
    }
    if(index.size() == 2){
        return std::string{s.substr(0,index.front())} + "%100" + s.substr(index.front()+1);
    }

    std::string str = s.substr(0,index[1]);
    for(std::size_t i = 1; i < index.size() ; ++i){
        str += ("%100" + s.substr(index[i]+1,index[i+1]-index[i]-1));
    }
    str += s.substr(index.back()+1);
    return str; // Placeholder
}

int main() {
    std::cout << (solution("abcdwa")) << std::endl;
    std::cout << (solution("banana")) << std::endl;
    std::cout << (solution("apple")) << std::endl;
    return 0;
}