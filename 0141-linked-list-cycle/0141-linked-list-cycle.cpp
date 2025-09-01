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
        // time & space comp: 
            // time: o(n) 
            // space: o(1) 
        
        // 1. declare our fast & slow ptrs here 
        ListNode *fastPtr = head; 
        ListNode *slowPtr = head; 

        // 2. start executing fast & slowptr tech. to see if == 
            // if == --> then we have a cycle! 
        while(fastPtr && fastPtr -> next)
        {
            slowPtr = slowPtr -> next;
            fastPtr = fastPtr -> next -> next; 

            // check for == 
            if(slowPtr == fastPtr)
            {
                return true;
            }
        }

        return false;
    }
};