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
        if(nums.size() == 0)
            return 0;
        else if(nums.size() == 1)
            return nums[0];
        //返回值j+1代表nums[j+1]的数在排序正确位置上
        auto PARTION = [&](vector<int>& nums,int begin,int end) -> int
        {
            int r = begin + rand() % (end - begin + 1);
	        swap(nums[r], nums[end]);
	        int q = nums[end];
	        int j = begin;
	        for (int m = begin; m < end ; ++m)
		        if (nums[m] < q)
			        swap(nums[m], nums[j++]);
	        swap(nums[j], nums[end]);
	        return j;
        };
        function<int(vector<int>&,int,int,int)> RANDOMIZED_SELECT = [&](vector<int>& nums,int begin,int end,int index) ->int
        {
            //目的是找到第index小的数
            if(begin == end)
                return nums[begin];
            int q = PARTION(nums,begin,end);//nums[q]在排序正确位置上
            int k = q - begin + 1;
            if(index < k)
                return RANDOMIZED_SELECT(nums, begin, q-1, index);
            else if(index > k)
                return RANDOMIZED_SELECT(nums, q+1, end,index-k);
            else
                return nums[q];
        };
        return RANDOMIZED_SELECT(nums, 0, nums.size()-1,nums.size()-k+1);
    }
    static int findKthLargest5(vector<int>& nums, int k)
    {
        //leetcode官方解法
        function<int(vector<int>, int, int, int)> quickselect=[](vector<int> &nums, int l, int r, int k) 
        {
            if (l == r)
                return nums[k];
            int partition = nums[l], i = l - 1, j = r + 1;
            while (i < j) 
            {
                do i++; while (nums[i] < partition);
                do j--; while (nums[j] > partition);
                if (i < j)
                    swap(nums[i], nums[j]);
            }
            if (k <= j)
                return quickselect(nums, l, j, k);
            else 
                return quickselect(nums, j + 1, r, k);
        }

        auto findKthLargest=[](vector<int> &nums, int k) 
        {
            int n = nums.size();
            return quickselect(nums, 0, n - 1, n - k);
        };
        return findKthLargest(nums, k);
    }
    static int finfindKthLargest6(vector<int>& nums, int k)
    {
        //堆排序
        
    }
}

int main()
{
    vector<int> nums = {3,2,1,5,6,4};
    int k = 2;
    cout << Solution::findKthLargest1(nums, k) << "\n";
    return 0;
}