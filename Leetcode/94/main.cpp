#include <iostream>
#include <vector>
#include <stack>
#include <functional>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),left(nullptr),right(nullptr){}
};

class solution
{
public:
    static vector<int> recursion(TreeNode* root)
    {
        if(!root)
            return {};
        std::function<void(TreeNode*,vector<int>&)> search = [&](TreeNode* root,vector<int>& res) -> void
        {
            if(!root)
                return;
            search(root->left,res);
            res.push_back(root->val);
            search(root->right,res);
        };
        vector<int> res;
        search(root,res);
        return res;
    }
    static vector<int> iterate(TreeNode* root)
    {
        if(!root)
            return {};
        stack<TreeNode*> s;
        vector<int> res;
        auto cur = root;
        while(cur || !s.empty())
        {
            while(cur)
            {
                s.push(cur);
                cur = cur->left;
            }
            cur = s.top();
            s.pop();
            res.push_back(cur->val);
            cur = cur->right;
        }
        return res;
    }
}

int main()
{
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);
    vector<int> res = solution::recursion(root);
    for(auto i:res)
    {
        cout<<i<<" ";
    }
    return 0;
}