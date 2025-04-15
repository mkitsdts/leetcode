# Leetcode 72
给你两个单词 word1 和 word2， 请返回将 word1 转换成 word2 所使用的最少操作数  。
你可以对一个单词进行如下三种操作：
插入一个字符
删除一个字符
替换一个字符

示例 1：
输入：word1 = "horse", word2 = "ros"
输出：3
解释：
horse -> rorse (将 'h' 替换为 'r')
rorse -> rose (删除 'r')
rose -> ros (删除 'e')

示例 2：
输入：word1 = "intention", word2 = "execution"
输出：5
解释：
intention -> inention (删除 't')
inention -> enention (将 'i' 替换为 'e')
enention -> exention (将 'n' 替换为 'x')
exention -> exection (将 'n' 替换为 'c')
exection -> execution (插入 'u')
 

提示：
0 <= word1.length, word2.length <= 500
word1 和 word2 由小写英文字母组成
------
这是一道很经典的动态规划题，通过推算字符串word1的前i个字符到字符串word2的前j个字符最小次数可以得到最终答案。

假如word1第i个字符等于word2第j个字符，那么不需要做任何变换，最小次数等于word1前i-1个字符转变为word2前j-1个字符的最小次数

假如不相等，那么最小次数就等于 min{word1前i-1个转变为word2前j字符增加一个字符,word1前i-1个字符转变word2前j-1个字符替换一个字符,word2前j-1个字符删掉一个字符} + 1