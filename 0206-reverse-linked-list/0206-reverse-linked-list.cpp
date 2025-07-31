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
        // tech: 2 pointers 

        // time & space comp: 
            // time: o(n) 
            // space: o(1) 
        
        // 1. create our pointers 
        ListNode *prev = nullptr; 
        ListNode *curr = head; 

        // 2. start reversing linked list 
        while(curr)
        {
            ListNode *tempNext = curr -> next; 

            // start reversing 
            curr -> next = prev; 
            prev = curr; 
            curr = tempNext; 
        }

        return prev;
    }
};