// 找出整型数组中占比超过一半的数

#include <cstddef>
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int solution(vector<int> array) {
    // Edit your code here
    size_t n = (array.size() + 1)/2;
    unordered_map<int,size_t> m;
    for(auto& i:array){
        ++m[i];
        if(m[i]>=n){
            return i;
        }
    }
    return -1;
}

int main() {
    // Add your test cases here
    
    cout << (solution({1, 3, 8, 2, 3, 1, 3, 3, 3}) == 3) << endl;
    
    return 0;
}