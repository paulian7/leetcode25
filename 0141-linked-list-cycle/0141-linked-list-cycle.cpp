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
        // cycle IF fastPtr == slowPtr 

        ListNode *fastPtr = head; 
        ListNode *slowPtr = head;

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