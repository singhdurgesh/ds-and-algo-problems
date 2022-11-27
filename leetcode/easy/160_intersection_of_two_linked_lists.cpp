/*
Problem Name: 160. Intersection of Two Linked Lists
Problem Link: https://leetcode.com/problems/intersection-of-two-linked-lists/
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int m=get_len(headA);
        int n=get_len(headB);

        if (m < n){
            return solver_answer(get_nth_node(headB, n-m), headA);
        }else if(m > n){
            return solver_answer(get_nth_node(headA, m-n), headB);
        }

        return solver_answer(headA, headB);
    }
    
    ListNode* solver_answer(ListNode* first, ListNode* second){
        if (first==NULL) return NULL;
        
        if (first == second) return first;
        return solver_answer(first->next, second->next);
    }

    int get_len(ListNode* node){
        if (node==NULL) return 0;

        return 1 + get_len(node->next);
    }
    
    ListNode* get_nth_node(ListNode* node, int n){
        cout<<n<<endl;
        ListNode* ans = node;
        while(n>0){
            ans = ans->next;
            n--;
        }
        cout<<ans->val;
        return ans;
    }
};
