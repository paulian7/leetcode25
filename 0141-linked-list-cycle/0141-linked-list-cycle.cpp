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
        // tech: 2 pointers 
            // fast and slowPtr 
                // fast x2 
                // slow x1 
            // if fast == slow --> cycle!, otherwise no cycle 

        // time & space comp: 
            // time: o(n)
            // space: o(1)
        
        // 1. create our pointers, default vals to head for now
        ListNode *fastPtr = head; 
        ListNode *slowPtr = head;

        // 2. start the cycle detection cycle 
            // while fastPtr is valid && is NOT the last node... 
        while(fastPtr && fastPtr -> next)
        {
            // update pointers 
            fastPtr = fastPtr -> next -> next; 
            slowPtr = slowPtr -> next; 

            // cycle detection test 
            if(fastPtr == slowPtr)
            {
                return true; // cycle detected
            }
        }

        return false; // all checks passed. no cycle
    }
};