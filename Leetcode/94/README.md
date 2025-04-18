# Leetcode 94
给定一个二叉树的根节点 root ，返回它的中序遍历
树中节点数目在范围 [0, 100] 内
-100 <= Node.val <= 100
------------------------------------------
看到这题，立刻想通过递归解决，只需要多写一个函数。
于是我使用上了一知半解地lambda函数。不出所料，编译失败，编译器报错如下
error: variable 'search' declared with deduced type 'auto' cannot appear in its own initializer
于是我把
auto search = [](TreeNode* root,vector<int>& res)->void{...}
改为
std::function<void(TreeNode*,vector<int>&)> search = [&](TreeNode* root,vector<int>& res) -> void{...}
就能通过编译并得到正确答案了
好奇对lambda函数的实现，所以去看了一眼lambda实现代码，有点复杂，还涉及到万能引用和转发等，暂时只能认识到lambda是一个基于模板实现的仿函数类，在定义之前调用就是在编译器还没有确定类型之前调用，这是不能实现的，再深层次的认识等后面看看std::forward再来补充
递归调用解决了中序遍历的问题，然后就在想递归能不能改成迭代的方式，经过一段时间思考，发现这是可以实现的，代码在main.cpp文件，这里记录一下主要思路
------------------------------------------
中序遍历的顺序是，先遍历左节点，然后遍历根节点，最后遍历右节点（对于最小单位一棵树而言）
按照这个顺序我们不难想到搜索策略，能往左就往左，不能往左就回溯往右，再继续往左...思想大致把一棵树拆成众多小的子树
确定了采取的策略，我们可以想到遍历需要一个栈记录往左走的过程中未访问过的节点，主要用于回溯，其他的都不是问题。
总结：这是一道很好的入门题