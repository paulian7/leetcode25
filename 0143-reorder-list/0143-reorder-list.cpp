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
        // time & space comp: 
            // time: o(n) 
            // space: o(1) 

        // 1. establish fast & slow ptrs 
        ListNode *slowPtr = head;
        ListNode *fastPtr = head -> next; 

        // 2. position our fast & slow ptrs 
        while(fastPtr && fastPtr -> next)
        {
            slowPtr = slowPtr -> next;
            fastPtr = fastPtr -> next -> next; 
        }

        // 3. establish new ptrs to start reversing 2nd half of list now 
        ListNode *startSec = slowPtr -> next; 
        
        // ensure there's a divide btwn the 2 halves 
        slowPtr -> next = nullptr; 

        ListNode *prevPtr = nullptr; 
        while(startSec != nullptr)
        {
            ListNode *tempNext = startSec -> next; 

            startSec -> next = prevPtr; 
            prevPtr = startSec;
            startSec = tempNext; 
        }

        // 4. add nodes accordingly now 
        ListNode *startHalf = head; 
        ListNode *startSecHalf = prevPtr; 
        while(startSecHalf != nullptr)
        {
            ListNode *tempNext1 = startHalf -> next;
            ListNode *tempNext2 = startSecHalf -> next; 

            startHalf -> next = startSecHalf; 
            startSecHalf -> next = tempNext1; 

            startHalf = tempNext1; 
            startSecHalf = tempNext2; 
        }

    }
};