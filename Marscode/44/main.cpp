// Ð¡EµÄÉä»÷ÑµÁ·
#include <iostream>
#include <cmath>
using namespace std;

int solution(int x, int y) {
    // PLEASE DO NOT MODIFY THE FUNCTION SIGNATURE
    // write code here
    double xx = static_cast<double>(x);
    double yy = static_cast<double>(y);
    double length = std::sqrt(xx * xx + yy * yy);
    if(length > 10)
        return 0;
    if(length > 9)
        return 1;
    if(length > 8)
        return 2;
    if(length > 7)
        return 3;
    if(length > 6)
        return 4;
    if(length > 5)
        return 5;
    if(length > 4)
        return 6;
    if(length > 3)
        return 7;
    if(length > 2)
        return 8;
    if(length > 1)
        return 9;
    if(length > 0)
        return 10;
    return -1;
}

int main() {
    cout << (solution(1, 0) == 10) << endl;
    cout << (solution(1, 1) == 9) << endl;
    cout << (solution(0, 5) == 6) << endl;
    cout << (solution(3, 4) == 6) << endl;
    return 0;
}