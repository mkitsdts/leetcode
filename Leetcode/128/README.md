# Leetcode 128
给定一个未排序的整数数组 nums ，找出数字连续的最长序列（不要求序列元素在原数组中连续）的长度。
请你设计并实现时间复杂度为 O(n) 的算法解决此问题。

-----------------------
刚开始是没有什么思路的，只能想到加入集合暴力搜索，这无法达到题目的要求。

思路转向优化暴力搜索，但一直没想出来很好的优化。加上有点困了，所以看了答案。

看了答案恍然大悟，要是元素存在连续序列中更小的值不搜索不就好了。然后写出了答案，chatgpt都能秒写出来，我给那操作一顿反而过不了。

无奈又得再次承认自己是飞舞