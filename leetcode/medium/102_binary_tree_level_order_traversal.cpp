/*
Problem Name: 102. Binary Tree Level Order Traversal
Problem URL: https://leetcode.com/problems/binary-tree-level-order-traversal/
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<pair<TreeNode*, int> > q;
        pair<TreeNode*, int> pp;
        int level;
        q.push(make_pair(root, 0));
        vector<vector<int> > v;
        while(!q.empty()){
            pp = q.front();
            q.pop();

            if(pp.first){
                level = pp.second;
                if (level == v.size()){
                    v.push_back({pp.first->val});
                }else{
                    v[level].push_back(pp.first->val);
                }

                q.push(make_pair(pp.first->left, level+1));
                q.push(make_pair(pp.first->right, level+1));
            }
        }

        return v;
    }
};
