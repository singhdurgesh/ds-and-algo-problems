/*
Problem Name: 116. Populating Next Right Pointers in Each Node
Problem Link: https://leetcode.com/problems/populating-next-right-pointers-in-each-node
*/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        map<int, Node*> mp;
        connectFill(root, 0, mp);
        return root;
    }

    void connectFill(Node* root, int depth, map<int, Node*> &mp){
        if (root){
            connectFill(root->right, depth+1, mp);
            root->next = mp[depth];
            mp[depth] = root;
            connectFill(root->left, depth+1, mp);
        }
    }
};
