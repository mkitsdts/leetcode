#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    static int subarraySum1(vector<int>& nums, int k) 
    {
        unordered_map<int, int> mp;
        int sum = 0;
        int count = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            if(mp.find(sum - k) != mp.end())
                count += mp[sum - k];
            ++mp[sum];
        }
        return count;
    }
    
    static int subarraySum2(vector<int>& nums, int k)
    {
        if(nums.empty())
            return 0;
        else if(nums.size() == 1)
            return nums[0] == k ? 1 : 0;

        int count = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            int sum = 0;
            for(int j = i; j < nums.size(); j++)
            {
                sum += nums[j];
                if(sum == k)
                    count++;
            }
        }
        return count;
    }
}

int main()
{
    std::vector<int> nums = {-1, -1, 1};
    int k = 0;
    cout << Solution::subarraySum(nums, k) << "\n";
    return 0;
}