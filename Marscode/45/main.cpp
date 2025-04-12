// 最少步数归零问题
#include <iostream>
#include <vector>

using namespace std;

int solution(int n, vector<int>& a) {
    // PLEASE DO NOT MODIFY THE FUNCTION SIGNATURE
    // write code here
    int res = 0;
    for(auto& i : a){
        while(i > 0){
            if(i % 10){
                ++res;
            }
            i /= 10;
        }
    }
    return res;
}

int main() {
    vector<int> a1 = {10, 13, 22, 100, 30};
    cout << (solution(5, a1) == 7) << endl;

    vector<int> a2 = {5, 50, 505};
    cout << (solution(3, a2) == 4) << endl;

    vector<int> a3 = {1000, 1, 10, 100};
    cout << (solution(4, a3) == 4) << endl;
}