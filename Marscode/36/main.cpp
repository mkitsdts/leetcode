// 饭馆菜品选择问题
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

long solution(const std::string& s, const std::vector<int>& a, int m, int k) {
    // PLEASE DO NOT MODIFY THE FUNCTION SIGNATURE
    // write code here
    int price = 0;
    vector<pair<char,int>> v;
    for(size_t i = 0; i < a.size(); ++i){
        v.push_back({s[i],a[i]});
    }
    sort(v.begin(),v.end(),[](pair<char,int> p1,pair<char,int> p2)->bool{
        return p1.second < p2.second;
    });
    for(size_t i = 0; i < a.size(); ++i){
        if(v[i].first=='0'){
            price += v[i].second;
            if(k-- == 1){
                return price;
            }
        }else{
            if(m>0){
                --m;
                price +=v[i].second;
                if(k-- == 1){
                    return price;
                }
            }
        }
    }
    return -1;
}

int main() {
    std::cout << (solution("001", {10, 20, 30}, 1, 2) == 30) << std::endl;
    std::cout << (solution("111", {10, 20, 30}, 1, 2) == -1) << std::endl;
    std::cout << (solution("0101", {5, 15, 10, 20}, 2, 3) == 30) << std::endl;
    return 0;
}