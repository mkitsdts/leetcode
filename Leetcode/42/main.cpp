/*
给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    static int trap(vector<int>& height){
        if(height.size() == 0)
            return 0;
        vector<int> left(height.size(),0);
        vector<int> right(height.size(),0);
        int MAX = 0;
        for(int i=0;i<height.size();++i){
            if(MAX < height[i]){
                MAX = height[i];
                left[i] = MAX;
            }else{
                left[i] = MAX;
            }
        }
        MAX = 0;
        for(int i=height.size()-1;i>=0;--i){
            if(MAX < height[i]){
                MAX = height[i];
                right[i] = MAX;
            }else{
                right[i] = MAX;
            }
        }
        int result = 0;
        for(int i=0;i<height.size();++i){
            int tmp = min(left[i],right[i]) - height[i];
            if(tmp > 0)
                result += tmp;
        }
        return result;

    }
}

int main(){
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout << Solution::trap(height) << endl;
    return 0;
}