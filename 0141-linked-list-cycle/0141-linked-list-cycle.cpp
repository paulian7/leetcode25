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
        // tech: 2 pointers approach! 
            // will have fast & slow ptr 
                // fast: moves 2 steps at a time 
                // slow: moves 1 step at a time 
            // if no cycle: 
                // fastPtr will eventually reach the end -> return false; 
            // if cycle: 
                // fastPtr will eventually meet up w/ slowPtr -> return true; 
        
        // time & space comp: 
            // time: o(n) 
            // space: o(1)
        
        
        // 1. declare & initalize our 2 ptrs (default to head first)
        ListNode *fastPtr = head; 
        ListNode *slowPtr = head;

        // 2. start our 2 ptrs strategy 
            // continue while loopin' until: 
                // fastPtr is valid && isn't the last node in the list
        while(fastPtr && fastPtr -> next)
        {
            // update ptrs accordingly 
            slowPtr = slowPtr -> next; 
            fastPtr = fastPtr -> next -> next; 

            // check for cycle now! 
            if(slowPtr == fastPtr)
            {
                return true; // cycle exists
            }
        }

        // 3. return false if fastPtr reaches the end
        return false;
    }
};