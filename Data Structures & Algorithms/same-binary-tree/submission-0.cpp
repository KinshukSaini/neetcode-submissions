/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    void solve(TreeNode* p, TreeNode* q, bool& same){
        if(!p || !q){
            if((!p && q) || (p && !q)){
                same = false;
            }
            return;
        }

        solve(p->left, q->left, same);
        solve(p->right, q->right, same);
        if(p->val != q->val) same = false;
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        bool same = true;
        solve(p, q, same);
        return same;
    }
};
