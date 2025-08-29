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
        // tech: fast & slow ptrs

        // time & space comp: 
            // time: o(n) 
            // space: o(1) 

        // 1. declare & initialize fast & slow ptrs
        ListNode *fastPtr = head; 
        ListNode *slowPtr = head;

        // 2. execute loop to identify whether or not cycle 
            // if fastPtr == slowPtr --> dealing w/ cycle! 
        while((fastPtr != nullptr) && (fastPtr -> next != nullptr))
        {
            slowPtr = slowPtr -> next; 
            fastPtr = fastPtr -> next -> next; 

            // 3. check for cycle: 
            if(slowPtr == fastPtr)
            {
                return true;
            }
        }

        // 4. otherwise, return false as loop terminated w/o any == 
        return false;
    }
};