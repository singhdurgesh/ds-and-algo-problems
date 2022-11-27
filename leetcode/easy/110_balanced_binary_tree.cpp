/*
Problem Name: 110. Balanced Binary Tree
Problem Link: https://leetcode.com/problems/balanced-binary-tree/
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
    bool temp=true;
    bool isBalanced(TreeNode* root) {
        int dept = dep(root);
        return temp;
    }
    int dep(TreeNode* root){
        if (root){
            int l = dep(root->left);
            int r = dep(root->right);
            if (abs(l-r)>1) {
                temp=false;
                return 0;
            }
            return max(l,r)+1;
        }
        return 0;
    }
};
