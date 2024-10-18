#include <iostream>

void moveZeroes(int* nums, int numsSize) 
{
    if(numsSize <= 1)
        return;
    int left = 0;
    int right = 1;
    while(right<=numsSize)
    {
        if(nums[left] == 0)
        {
            while(right<numsSize)
                if(nums[right++]!=0)
                    break;
            int tmp = nums[--right];
            nums[right] = 0;
            nums[left++] = tmp;
            right = left + 1;
        }
        else
        {
            ++left;
            right = left + 1;
        }
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