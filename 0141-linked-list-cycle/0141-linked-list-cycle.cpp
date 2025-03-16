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
        // tech: 2 ptrs approach --> time comp: o(n) 
            // space comp: o(1), constant time 

            // fast ptr: moves 2 steps at a time 
            // slow ptr: moves 1 step at a time 
        
        // if no cycle: 
            // fast ptr will eventually reach the end -> false 
        // if cycle: 
            // fast ptr will eventually meet up w/ slow ptr -> true

        // 1. initialize pointers 
        ListNode *slowPtr = head; 
        ListNode *fastPtr = head;

        // 2. iterate thr linked list as long as fastPtr hasn't reached end 
        while(fastPtr && fastPtr -> next)
        {
            // update ptrs accordingly 
            slowPtr = slowPtr -> next;
            fastPtr = fastPtr -> next -> next; 

            // check for cycle (aka when slow == fast)
            if(slowPtr == fastPtr)
            {
                return true; // cycle exists!
            }
        }

        return false;
    }
};