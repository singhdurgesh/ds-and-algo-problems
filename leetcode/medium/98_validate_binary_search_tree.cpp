/*
Problem Name: 98. Validate Binary Search Tree
Problem URL: https://leetcode.com/problems/validate-binary-search-tree/
*/

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
    bool isValidBST(TreeNode* root, long long from_val = (long long)INT_MIN - 1, long long to_val = (long long)INT_MAX + 1) {
        if (!root) return true;

        if (root->val <= from_val || root->val >= to_val) return false;

        int ans = true;
        if(root->right){
            if (root->right->val <= root->val) return false;
            ans &= isValidBST(root->right,max((long long)root->val, from_val), to_val);
        }

        if(root->left){
            if (root->left->val >= root->val) return false;
            ans &= isValidBST(root->left, from_val, min((long long)root->val, to_val));
        }
        return ans;
    }
};
