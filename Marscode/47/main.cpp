// 完美偶数计数
#include <iostream>
#include <vector>
using namespace std;

int solution(int n, int l, int r, vector<int>& a) {
    // PLEASE DO NOT MODIFY THE FUNCTION SIGNATURE
    // write code here
    int res = 0;
    for(size_t i = 0; i < a.size(); ++i){
        if(a[i] <= r && a[i] >= l && ((a[i] & 1) == 0)){
            ++res;
        }
    }
    return res;
}

int main() {
    vector<int> a1 = {1, 2, 6, 8, 7};
    cout << (solution(5, 3, 8, a1) == 2) << endl;

    vector<int> a2 = {12, 15, 18, 9};
    cout << (solution(4, 10, 20, a2) == 2) << endl;

    vector<int> a3 = {2, 4, 6};
    cout << (solution(3, 1, 10, a3) == 3) << endl;
}