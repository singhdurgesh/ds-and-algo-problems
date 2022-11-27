/*
Problem Name: 100. Same Tree
Problem Link: https://leetcode.com/problems/same-tree/
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p and q){
            if (p->val==q->val){
                return isSameTree(p->left,q->left)&isSameTree(p->right,q->right);
            }
            return false;
        }
        if (p or q) return false;
        return true;
    }
};
