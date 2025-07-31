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
        // time: o(n) 
        // space: o(1)

        // 1. create 2 ptrs
        ListNode *slowPtr = head; 
        ListNode *fastPtr = head; 

        while(fastPtr && fastPtr -> next)
        {
            slowPtr = slowPtr -> next;
            fastPtr = fastPtr -> next -> next; 

            if(slowPtr == fastPtr)
            {
                return true;
            }
        }

        return false;
    }
};