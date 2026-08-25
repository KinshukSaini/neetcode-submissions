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
    vector<int> res;
    void dfs(TreeNode* root, int depth, int& maxDepth){
        if(depth > maxDepth){
            res.push_back(root->val);
            maxDepth = depth;
        } 
        if(root->right) dfs(root->right, depth + 1, maxDepth);
        if(root->left) dfs(root->left, depth + 1, maxDepth);
    }
    vector<int> rightSideView(TreeNode* root) {
        if(!root) return {};
        int maxDepth = -1;
        dfs(root, 0, maxDepth);
        return res;
    }
};
