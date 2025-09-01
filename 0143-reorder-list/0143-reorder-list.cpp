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
        // tech: fast & slow ptrs, 
            // find pivot, split list, reverse 2nd half, then add accordingly

        // time & space comp: 
            // time: o(n)
            // space: o(1) 
        
        // 1. create our fast & slow ptrs 
        ListNode *slowPtr = head; 
        ListNode *fastPtr = head -> next; // our fastPtr.. want it to be ahead of slowPtr

        // 2. move ptrs to correct spot 
            // til fastPtr reaches the end, or is the last node 
        while((fastPtr != nullptr) && (fastPtr -> next != nullptr)) 
        {
            slowPtr = slowPtr -> next; 
            fastPtr = fastPtr -> next -> next; 
        }

        // 3. start reversing the 2nd half of the list 
        ListNode *startSec = slowPtr -> next; 

        // ensure 2 lists are separated 
        slowPtr -> next = nullptr; 

        ListNode *prevPtr = nullptr; 
        while(startSec != nullptr)
        {
            ListNode *tempNext = startSec -> next; 

            startSec -> next = prevPtr; 
            prevPtr = startSec; 
            startSec = tempNext; 
        }

        // 4. add nodes accordingly from each of the halves 
        ListNode *firstHalf = head; 
        ListNode *secHalf = prevPtr; 
        while(secHalf != nullptr)
        {
            ListNode *tempNext1 = firstHalf -> next; 
            ListNode *tempNext2 = secHalf -> next; 

            firstHalf -> next = secHalf; 
            secHalf -> next = tempNext1; 

            firstHalf = tempNext1; 
            secHalf = tempNext2; 
        }
    }
};