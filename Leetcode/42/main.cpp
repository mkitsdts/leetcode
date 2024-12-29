/*
���� n ���Ǹ�������ʾÿ�����Ϊ 1 �����ӵĸ߶�ͼ�����㰴�����е����ӣ�����֮���ܽӶ�����ˮ��
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    static int trap(vector<int>& height){
        if(height.size() == 0){
            return 0;
        }
        int n = height.size() - 1;
        int left = 0, right = 1;
        int res = 0;
        int mid = 0;
        while(left < n){
            if(height[right] >= height[left]){
                res += ((right - left - 1) * height[left] - mid);
                left = right;
                mid = 0;
                right = left + 1;
            }else{
                mid += height[right];
                ++right;
                if(right == n + 1){
                    if(left == n - 1){
                        break;
                    }
                    mid = 0;
                    ++left;
                    right = left + 1;
                }
            }
        }

        return res;
    }
}

int main(){
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout << Solution::trap(height) << endl;
    return 0;
}