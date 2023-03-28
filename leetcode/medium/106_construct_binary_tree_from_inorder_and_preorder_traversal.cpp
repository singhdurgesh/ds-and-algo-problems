/*
Problem Name: 106. Construct Binary Tree from Inorder and Postorder Traversal
Problem Link: https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildTreeResult(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1);
    }

    TreeNode* buildTreeResult(vector<int>& preorder, int pl, int pr, vector<int>& inorder, int il, int ir){
        if (pl > pr || il > ir || pr<0 || ir<0 || pl >= preorder.size() || il >= inorder.size()) return NULL;

        TreeNode* node = new TreeNode(preorder[pl]);
        int ind = -1;
        for(int i=il; i<=ir; i++){
            if (inorder[i]==preorder[pl]){
                ind = i;
            }
        }

        node->left = buildTreeResult(preorder, pl+1, pr, inorder, il, ind-1);
        node->right = buildTreeResult(preorder, pl+1+ind-il, pr, inorder, ind+1, ir);
        return node;
    }
};
