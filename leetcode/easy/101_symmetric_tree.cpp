/*
Problem Name: 101. Symmetric Tree
Problem Link: https://leetcode.com/problems/symmetric-tree/
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
    bool isSymmetric(TreeNode* root) {
        if (root==NULL){
            return true;
        }
        return isTreeSymmetric(root->left, root->right);
    }
    
    bool isTreeSymmetric(TreeNode* left, TreeNode* right){
        if (left==NULL && right==NULL){
            return true;
        }
        
        if (left==NULL || right==NULL){
            return false;
        }
        
        if (left->val != right->val){
            return false;
        }
        
        bool ans = isTreeSymmetric(left->left, right->right);
        ans &= isTreeSymmetric(left->right, right->left);
        return ans;
    }
};
