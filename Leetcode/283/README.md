# Leetcode 283
给定一个数组 nums ，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。
请注意 ，必须在不复制数组的情况下原地对数组进行操作。

1 <= nums.length <= 10^4
-2^31 <= nums[i] <= 2^31 - 1

最容易想到的是下面这种方式，开辟一个新的数组，把所以非0值复制到数组，这种方案需要O(n)的时间复杂度和O(n)的空间复杂度
我觉得是性价比比较高的
------------------------------------------------------
但是题目说只要O(1)的空间复杂度，那我们就得想办法不要开辟新的数组
然后就很自然想到双指针法，左指针负责定位，右指针负责寻找非0值，找到后交换左右指针的值，这样就优化到了O(1)的空间复杂度