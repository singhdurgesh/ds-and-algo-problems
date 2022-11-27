  /*
  Problem Name: 94. Binary Tree Inorder Traversal
  Problem: https://leetcode.com/problems/binary-tree-inorder-traversal/
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        if (root == NULL){
            return ans;
        }
        ans = inorderTraversal(root->left);
        ans.push_back(root->val);
        
        vector<int> ans2;
        ans2 = inorderTraversal(root->right);
        for(int i=0; i<ans2.size(); i++){
            ans.push_back(ans2[i]);
        }
        return ans;
    }
};
