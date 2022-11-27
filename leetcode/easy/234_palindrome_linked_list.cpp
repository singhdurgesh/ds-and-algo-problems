/*
Problem Name: 234. Palindrome Linked List
Problem Link: https://leetcode.com/problems/palindrome-linked-list/
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        vector<int> v;
        ListNode *slow, *fast, *prev;
        slow = head;
        fast = head;
        int dd = 0;
        while(slow!=NULL && fast != NULL){
            v.push_back(slow->val);
            prev = slow;
            slow = slow->next;
            fast = fast->next;
            if (fast!=NULL) {fast = fast->next;}
            else{
                dd = 1;
            }
        }

        int i = v.size()-1;
        if (dd==1){
            slow = prev;
        }
        while(slow!=NULL){
            if (slow->val != v[i]) return false;
            slow = slow->next;
            i--;
        }
        return true;
    }
};
