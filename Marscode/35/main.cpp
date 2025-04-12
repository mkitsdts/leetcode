// Ð¡sµÄµ¹ÅÅË÷Òý
#include <iostream>
#include <vector>
using namespace std;

vector<int> solution(vector<int>& a, vector<int>& b) {
    // PLEASE DO NOT MODIFY THE FUNCTION SIGNATURE
    // write code here
    int ar = a.size() - 1,br = b.size() - 1;
    vector<int> res;
    while(ar > 0 || br > 0){
        cout << "ar: " << ar << " br: " << br<<endl;
        if(a[ar] == b[br]){
            res.push_back(a[ar]);
            if(ar>0){
                --ar;
            }
            if(br>0){
                --br;
            }
        }else if(a[ar]<b[br]){
            if(br>0){
                --br;
            }else{
                break;
            }
        }else if(a[ar]>b[br]){
            if(ar>0){
                --ar;
            }else{
                break;
            }
        }
    }
    if(a[ar]==b[br]){
        res.push_back(a[ar]);
    }
    return res;
}

int main() {
    vector<int> a4 = {1, 2, 3,7};
    vector<int> b4 = {2, 5, 7};
    vector<int> res4 = solution(a4, b4);
    cout << (res4 == vector<int>{7, 2}) << endl;

    return 0;
}