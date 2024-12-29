// 数列差异的最小化
#include <climits>
#include <iostream>
#include <vector>
#include <cmath>

int solution(int n, int m, int k, std::vector<int>& a, std::vector<int>& b) {
    // Please write your code here
    int min = 1000000000;
    int res = INT_MAX;
    for(auto& i : a){
        for(auto& j : b ){
            auto tmp = std::abs(std::abs(i-j)-k);
            std::cout<<"tmp:" << tmp <<std::endl;
            if(tmp == 0){
                std::cout<<"i and j when tmp = 0: " << i <<" "<<j<<std::endl;
                return 0;
            }
            if(tmp<=min){
                min = tmp;
                res = std::min((std::abs((i-j)*(i-j)-(k*k))),res);
                std::cout<<"i and j:" << i <<" "<<j<<" res: "<<res<<std::endl;
            }
        }
    }
    std::cout<<"res: "<<res<<std::endl;
    return res;
}

int main() {
    // You can add more test cases here
    // case 1
    std::vector<int> a1 = {5, 3, 4, 1, 2};
    std::vector<int> b1 = {0, 6, 7, 9, 8};
    std::cout << (solution(5, 5, 1, a1, b1) == 0) << std::endl;

    // case 2
    std::vector<int> a2 = {5, 3, 4, 1, 2};
    std::vector<int> b2 = {0, 6, 7, 9, 8};
    std::cout << (solution(5, 5, 0, a2, b2) == 1) << std::endl;

    // case 3
    std::vector<int> a3 = {5, 3, 4, 1, 2};
    std::vector<int> b3 = {0, 6, 7, 9, 8, 11};
    std::cout << (solution(5, 6, 3, a3, b3) == 0) << std::endl;

    std::vector<int> a4 = {20,2,19,11,5,4,12,20,19,7,8,14,2,11,
    24,12,8,4};
    std::vector<int> b4 = {10};
    std::cout << (solution(18, 1, 7, a4, b4) == 13) << std::endl;

    return 0;
}