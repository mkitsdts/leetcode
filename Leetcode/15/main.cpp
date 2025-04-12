#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    static vector<vector<int>>& threeSum(vector<int>& nums) {
        if(nums.size() < 3) 
            return {};
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for(auto i = 0; i < nums.size(); ++i){
            if(nums[i] > 0)
                break;
            if(i > 0 && nums[i] == nums[i-1]) 
                continue;
            int left = i + 1;
            int right = nums.size() - 1;
            while(left < right){
                int sum = nums[i] + nums[left] + nums[right];
                if(sum == 0){
                    res.push_back({nums[i], nums[left], nums[right]});
                    while(left < right && nums[left] == nums[left+1]){ 
                        ++left;
                    }
                    while(left < right && nums[right] == nums[right-1]){ 
                        --right;
                    }
                    ++left;
                    --right;
                }else if(sum < 0){
                    ++left;
                }else{
                    --right;
                }
            }
        }
        return res;
    }
};


int main(){
    vector<int> nums = {-1,0,1,2,-1,-4};
    vector<vector<int>> res = Solution::threeSum(nums);
    for (auto vec : res) {
        for (auto num : vec) {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}