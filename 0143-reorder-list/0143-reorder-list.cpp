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
    void reorderList(ListNode* head) {
        // tech: fast & slow ptrs to identify mid list
            // reverse 2nd half of list 
            // add nodes accordingly from there 

        // time & space comp: 
            // time: o(n)
            // space: o(1)
        
        // 1. declare our fast & slow ptrs 
        ListNode *slowPtr = head; 
        ListNode *fastPtr = head -> next;

        // 2. position our pointers in the corr spot 
            // keep iterating til fastPtr reaches end of list OR...
            // ... last val of list
            // slowPtr will be 1 node before the "start of 2nd half" 
        while(fastPtr && fastPtr -> next)
        {
            slowPtr = slowPtr -> next;
            fastPtr = fastPtr -> next -> next; 
        }

        // 3. establish start of secHalf of list, then chop off ties
            // .. want to separate 1st and 2nd half of list
        ListNode *startHalf = slowPtr -> next; 
        slowPtr -> next = nullptr; 

        // 4. start algo for reversing 2nd half of list 
        ListNode *prevPtr = nullptr; 
        while(startHalf != nullptr)
        {
            ListNode *tempNext = startHalf -> next; 

            startHalf -> next = prevPtr; 
            prevPtr = startHalf; 
            startHalf = tempNext; 
        }

        // 5. start adding nodes accordingly from each half now 
        ListNode *startFirst = head; 
        ListNode *startSec = prevPtr; 
        while(startSec != nullptr)
        {
            ListNode *tempNext1 = startFirst -> next;
            ListNode *tempNext2 = startSec -> next; 

            startFirst -> next = startSec; 
            startSec -> next = tempNext1; 

            startFirst = tempNext1; 
            startSec = tempNext2; 
        }
    }
};