/*
Problem Link-> https://www.interviewbit.com/problems/next-greater-number-bst/
Similiar Problem-> Inorder Suceessor in BST
*/
*/

// * Definition for binary tree
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

typedef struct TreeNode treenode;

treenode* treenode_new(int val) {
    treenode* node = (treenode *) malloc(sizeof(treenode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

/**
 * @input A : Root pointer of the tree 
 * @input B : Integer
 * 
 * @Output root pointer of tree.
 */

treenode* ans;
int finded = 0;

treenode* inorderTraversal(treenode* A, int B) {
    if (!A) return A;

    treenode *left, *right;
    left = inorderTraversal(A->left, B);
    if (finded == 1){
        ans = A;
        finded ++;
        return A;
    }
    if (A->val == B) {
        finded += 1;
    }
    right = inorderTraversal(A->right, B);
    return ans;
}

treenode* getSuccessor(treenode* A, int B) {
    finded = 0;
    ans = NULL;
    return inorderTraversal(A, B);
}
