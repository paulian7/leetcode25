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
    ListNode* reverseList(ListNode* head) {
        // time & space comp: 
            // time:
            // space: 
        
        // 1. create 2 pointers 
        ListNode *curr = head; 
        ListNode *prev = nullptr; 

        // 2. start reversing & iterating thr the list 
        while(curr != nullptr) 
        {
            ListNode *tempNext = curr -> next; 

            curr -> next = prev; 
            prev = curr; 
            curr = tempNext; 
        }

        return prev; 
    }
};