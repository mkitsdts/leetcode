// 徒步旅行中的补给问题
#include <iostream>
#include <vector>

int solution(int n, int k, std::vector<int> data) {
    // Edit your code here
    std::vector<int> day_cast(n,0);
    day_cast[0]=data[0];
    int min = std::min(data[0],data[1]);
    for(int i = 1; i < k; ++i){
        min=std::min(data[i],min);
        day_cast[i] = day_cast[i-1] + min;
    }

    auto m =[&](int index){
        if(k==1){
            min=data[index];
            return;
        }
        min=std::min(data[index],data[index-1]);
        for(int j = 1; j < k - 1; ++j){
            min=std::min(min,data[index-j-1]);
        }
    };

    for(int i = k; i < n; ++i){
        m(i);
        std::cout<<"m处理后的min: "<<min<<std::endl;
        day_cast[i] = day_cast[i-1] + min;
    }

    for(auto& a:day_cast){
        std::cout<<a<<" ";
    }
    std::cout<<std::endl;
    std::cout<<"day_cast[n-1]: "<<day_cast[n-1]<<std::endl;
    return day_cast[n-1];
}

int main() {
    // Add your test cases here

    std::cout << (solution(5, 2, {1, 2, 3, 3, 2}) == 9) << std::endl;
    std::cout << (solution(6, 3, {4, 1, 5, 2, 1, 3}) == 9)<<std::endl;
    std::cout << (solution(4, 1, {3, 2, 4, 1}) == 10)<<std::endl;
    return 0;
}