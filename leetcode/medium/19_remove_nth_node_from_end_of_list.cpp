/*
Problem Name: 19. Remove Nth Node From End of List
Problem Link: https://leetcode.com/problems/remove-nth-node-from-end-of-list/
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = getListNodeLength(head);
        
        if (len==n) return head->next;
        
        int curr = 0;
        ListNode* curr_node = head;
        while(curr_node->next){
            if (curr == len - n -1){
                ListNode* temp = curr_node->next->next;
                curr_node->next = temp;
                break;
            }
            curr++;
            curr_node = curr_node->next;
        }

        return head;
    }

    int getListNodeLength(ListNode* head){
        int ans =0;
        while(head){
            head = head->next;
            ans++;
        }
        return ans;
    }
};
