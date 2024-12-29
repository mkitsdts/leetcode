// 构造特定数组的逆序拼接
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(int n) {
    // PLEASE DO NOT MODIFY THE FUNCTION SIGNATURE
    // write code here
    vector<int> res;
    for(int i = n; i > 0; --i){
        for(int j = n; j > n - i; --j){
            res.push_back(j);
        }
    }
    for(auto& i:res){
        cout<<i<<" ";
    }
    cout<<endl;
    return res;
}

int main() {
    vector<int> result1 = solution(3);
    cout << (result1 == vector<int>{3, 2, 1, 3, 2, 3}) << endl;

    vector<int> result2 = solution(4);
    cout << (result2 == vector<int>{4, 3, 2, 1, 4, 3, 2, 4, 3, 4}) << endl;

    vector<int> result3 = solution(5);
    cout << (result3 == vector<int>{5, 4, 3, 2, 1, 5, 4, 3, 2, 5, 4, 3, 5, 4, 5}) << endl;

    return 0;
}