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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) return {};
        vector<pair<int, int>> pairs;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        while(!q.empty()){
            auto p = q.front();
            TreeNode* node = p.first;
            int lvl = p.second;
            pairs.push_back({node->val, lvl});
            q.pop();

            if(node->left) q.push({node->left, lvl + 1});
            if(node->right) q.push({node->right, lvl + 1});
        }
        int n = pairs[pairs.size() - 1].second;
        vector<vector<int>> res(n + 1);
        for(auto p : pairs) res[p.second].push_back(p.first);
        return res;
    }
};
