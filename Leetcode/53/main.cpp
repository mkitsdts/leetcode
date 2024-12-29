#include <iostream>
#include <vector>
using namespace std;

class Solution 
{
public:
    static int maxSubArray(vector<int>& nums) 
    {
        if(nums.size() == 0)
            return 0;
        else if(nums.size() == 1)
            return nums[0];

        int sum = nums[0];
        int MAX = 1<<31;
        for(int i = 1; i < nums.size(); i++)
        {
            sum = max(sum + nums[i], nums[i]);
            if(sum > MAX)
                MAX = sum;
        }
        return MAX;
    }
    
    struct Status 
    {
        int lSum, rSum, mSum, iSum;
    };

    Status pushUp(Status l, Status r) 
    {
        int iSum = l.iSum + r.iSum;
        int lSum = max(l.lSum, l.iSum + r.lSum);
        int rSum = max(r.rSum, r.iSum + l.rSum);
        int mSum = max(max(l.mSum, r.mSum), l.rSum + r.lSum);
        return (Status) {lSum, rSum, mSum, iSum};
    };

    Status get(vector<int> &a, int l, int r) 
    {
        if (l == r) 
        {
            return (Status) {a[l], a[l], a[l], a[l]};
        }
        int m = (l + r) >> 1;
        Status lSub = get(a, l, m);
        Status rSub = get(a, m + 1, r);
        return pushUp(lSub, rSub);
    }

    int maxSubArray(vector<int>& nums) 
    {
        return get(nums, 0, nums.size() - 1).mSum;
    }
};

int main()
{
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    cout << Solution::maxSubArray(nums) << endl;
    vector<int> nums = {5,4,-1,7,8};
    cout << Solution::maxSubArray(nums) << endl;
    return 0;
}
