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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int mini = min(p->val, q->val);
        int maxi = max(p->val, q->val);
        
        TreeNode* node = root;
        while(node){
            if(node->val > mini && node->val < maxi) return node;
            else if(node->val < mini){
                if(node->val == mini || node->val == maxi) return node;
                node = node->right;
            }
            else{
                if(node->val == maxi || node->val == mini) return node;
                node = node->left;
            }
        }
        return NULL;
    }
};
