# Leetcode 283
给定一个数组 nums ，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。
请注意 ，必须在不复制数组的情况下原地对数组进行操作。

1 <= nums.length <= 10^4
-2^31 <= nums[i] <= 2^31 - 1

先想到的下面这种方式，O(n^2)的时间复杂度和O(1)的空间复杂度
void moveZeroes(int* nums, int numsSize)
{
    if(numsSize <= 1)
        return;
    int left = 0;
    int right = 1;
    while(right <= numsSize)
    {
        if(nums[left])
        {
            int tmp = nums[right];
            nums[right] = 0;
            nums[left++] = tmp;
        }
        ++left;
        right = left + 1;
    }
}
运行耗时105ms，远远高于平均，经过优化，把嵌套的小while循环
思想是这样，把右边的非零值全部移到左边，那最后剩下的都是零
void moveZeroes(int* nums, int numsSize)
{
    if(numsSize <= 1)
        return;
    int left = 0;
    int right = 0;
    while(right < numsSize)
    {
        if(nums[right])
        {
            int tmp = nums[right];
            nums[right] = 0;
            nums[left++] = tmp;
        }
        ++right;
    }
}
运行，得到还算满意的结果