/*
Problem Name: 108. Convert Sorted Array to Binary Search Tree
Problem Link: https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/
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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode* root = new TreeNode(5);
        root =  solve(0,nums.size(),nums);
        return root;
    }
    TreeNode* solve(int i,int j,vector<int> &v){
        if(i==j) return NULL;
        if (j-i==1){
            TreeNode* temp = new TreeNode(v[i]);
            return temp;
        }
        int mid = (i+j)/2;
        TreeNode* temp = new TreeNode(v[mid]);
        temp->left = solve(i,mid,v);
        temp->right = solve(mid+1,j,v);
        return temp;
    }
};
