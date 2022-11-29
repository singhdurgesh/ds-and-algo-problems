/*
Problem Name: 2. Add Two Numbers
Problem Link: https://leetcode.com/problems/add-two-numbers/
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* curr = NULL;
        ListNode* ans = NULL;
        int val = 0, sum;

        while(l1 && l2){
            sum = l1->val + l2->val + val;

            ListNode* temp = new ListNode(sum%10);
            if(!curr){
                curr = temp;
                ans = temp;
            }else{
                curr->next = temp;
                curr = curr->next;
            }
            val = sum/10;
            l1 = l1->next;
            l2 = l2->next;
        }

        while(l1){
            sum = l1->val + val;
            ListNode* temp = new ListNode(sum%10);
            if (!curr){
                curr = temp;
                ans = temp;
            }else{
                curr->next = temp;
                curr = curr->next;
            }
            val = sum/10;
            l1 = l1->next;
        }
        
        while(l2){
            sum = l2->val + val;
            ListNode* temp = new ListNode(sum%10);
            if (!curr){
                curr = temp;
                ans = temp;
            }else{
                curr->next = temp;
                curr = curr->next;
            }
            val = sum/10;
            l2 = l2->next;
        }

        while(val){
            ListNode* temp = new ListNode(val%10);
            if (!curr){
                curr = temp;
                ans = temp;
            }else{
                curr->next = temp;
                curr = curr->next;
            }
            val/=10;
        }
        
        return ans;
    }
};
