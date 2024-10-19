#include <iostream>

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

int main()
{
    int *nums;
    int numsSize;
    scanf("%d",&numsSize);
    nums = static_cast<int>(malloc(numsSize * sizeof(int)));
    moveZeroes(nums,numsSize);
    return 0;
}