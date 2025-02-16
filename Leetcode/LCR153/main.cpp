#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> pathTarget(TreeNode* root, int target) {
        if(!root){
            return {};
        }
        deque<TreeNode*> path;
        path.push_back(root);
        vector<vector<int>> sum;
        function<void(TreeNode*,int)> func =[&](TreeNode* r,int tar) -> void {
            if(!path.empty()) r = path.back();
            else return;
            if(!r->left&&!r->right){
                if(tar==target){
                    auto index = path.size();
                    if(index) sum.push_back(vector<int>{});
                    else return;
                    for(size_t i = 0; i < index ; ++i){
                        sum.back().push_back(path[i]->val);
                    }
                    path.pop_back();
                    return;
                }
                path.pop_back();
                return;
            }
    
            if(r->left!=nullptr){
                path.push_back(r->left);
                func(r->left,tar+r->left->val);
            }
            if(r->right!=nullptr){
                path.push_back(r->right);
                func(r->right,tar+r->right->val);
            }
    
            path.pop_back();
        };
        func(root,root->val);
        return sum;
    }
};