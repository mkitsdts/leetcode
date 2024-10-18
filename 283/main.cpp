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
    int nums[10000];
    int numsSize;
    scanf("%d",&numsSize);
    moveZeroes(nums,numsSize);
    return 0;
}