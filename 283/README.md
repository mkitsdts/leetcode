# Leetcode 283
����һ������ nums ����дһ������������ 0 �ƶ��������ĩβ��ͬʱ���ַ���Ԫ�ص����˳��
��ע�� �������ڲ���������������ԭ�ض�������в�����

1 <= nums.length <= 10^4
-2^31 <= nums[i] <= 2^31 - 1

���뵽���������ַ�ʽ��O(n^2)��ʱ�临�ӶȺ�O(1)�Ŀռ临�Ӷ�
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
���к�ʱ105ms��ԶԶ����ƽ���������Ż�����Ƕ�׵�Сwhileѭ��
˼�������������ұߵķ���ֵȫ���Ƶ���ߣ������ʣ�µĶ�����
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
���У��õ���������Ľ��