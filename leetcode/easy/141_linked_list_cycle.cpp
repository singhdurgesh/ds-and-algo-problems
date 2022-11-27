/*
Problem Name: 141. Linked List Cycle
Problem Link: https://leetcode.com/problems/linked-list-cycle/
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
    bool hasCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast;
        
        if (head != NULL){
            fast = head->next;
        }
        while(slow != fast && slow != NULL && fast != NULL){
            slow = slow->next;
            fast = fast->next;
            if (fast != NULL) fast = fast->next;
        }
        
        if (slow == NULL || fast == NULL){
            return false;
        }
        return true;
    }
};
