#include <iostream>
#include <vector>
#include <algorithm>
#include <priority_queue>
#include <functional>
#include <random>
using namespace std;

class Solution
{
public:
    static int findKthLargest1(vector<int>& nums, int k) 
    {
        //排序
        sort(nums.begin(),nums.end(),greater<int>());
        return nums[k];
    }
    static int findKthLargest2(vector<int>& nums, int k) 
    {
        //最大堆
        priority_queue<int> pq;
        for(int i=0;i<nums.size();++i)
        {
            pq.push(nums[i]);
        }
        for(int i=1;i<k;++i)
        {
            pq.pop();
        }
        return pq.top();
    }
    static int findKthLargest3(vector<int>& nums, int k) 
    {
        //最小堆
        priority_queue<int,vector<int>,greater<int>> pq;
        for(int i=0;i<nums.size();++i)
        {
            pq.push(nums[i]);
            if(pq.size()>k)
            {
                pq.pop();
            }
        }
        return pq.top();
    }
    static int findKthLargest4(vector<int>& nums, int k) 
    {
        //快速选择
        auto PARTION = [&](vector<int>& nums,int begin,int end) -> int
        {
            int k = begin + rand() % (end - begin + 1);
	        swap(nums[k], nums[end]);
	        int q = nums[end];
	        int j = begin - 1;
	        for (int m = begin; m < end ; ++m)
	        {
		        if (nums[m] < nums[end])
		        {
			        ++j;
			        swap(nums[m], nums[j]);
		        }
	        }
	        swap(nums[j + 1], nums[end]);
	        return j + 1;
        };
        function<int(vector<int>&,int,int)> RANDOMIZED_SELECT = [&](vector<int>& nums,int left,int index) ->int
        {
            int q = PARTION(nums,left,nums.size()-1);
            int k = q - left + 1;
            if(index < k)
                return RANDOMIZED_SELECT(nums, left, q-1);
            else if(index > k)
                return RANDOMIZED_SELECT(nums, q+1, index-k);
            else
                return nums[q];
        };
        return RANDOMIZED_SELECT(nums, 0, nums.size() - k);
    }
}

int main()
{
    vector<int> nums = {3,2,1,5,6,4};
    int k = 2;
    cout << Solution::findKthLargest1(nums, k) << "\n";
    return 0;
}