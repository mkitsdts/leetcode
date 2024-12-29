// 统计班级中的说谎者
#include <iostream>
#include <vector>
#include <algorithm>

int solution(std::vector<int> A) {
    // Edit your code here
    if(A.size()==1){
        return 1;
    }else if(A.size() == 0){
        return 0;
    }
    sort(A.begin(),A.end()); 
    auto size = A.size() / 2;
    for(int i = size - 1; i >= 0;--i){
        std::cout << "i: " << i << std::endl;
        if(A[i] == A[i+1]){
            ++size;
        }else{
            return A.size() & 1 ? size + 1 : size;
        }
    }
    return A.size() & 1 ? size + 1 : size;
}

int main() {
    // Add your test cases here
    std::cout << (solution({100, 100, 100}) == 3) << std::endl;
    std::cout << (solution({2, 1, 3}) == 2) << std::endl;
    std::cout << (solution({30, 1, 30, 30}) == 3) << std::endl;
    std::cout << (solution({19, 27, 73, 55, 88}) == 3) << std::endl;
    std::cout << (solution({19, 27, 73, 55, 88, 88, 2, 17, 22}) == 5) << std::endl;
    return 0;
}