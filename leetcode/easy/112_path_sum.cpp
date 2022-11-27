/*
Problem Name: 112. Path Sum 
Problem Link: https://leetcode.com/problems/path-sum/
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if (!root) return false;
        return hasPathSu(root,sum);
    }
    bool hasPathSu(TreeNode* root,int sum){
        if (root){
            if (!root->left and !root->right){
                if (sum==root->val) return true;
                return false;
            }
            return hasPathSu(root->left,sum-root->val) or hasPathSu(root->right,sum-root->val);
        }
        return false;
    }
};
