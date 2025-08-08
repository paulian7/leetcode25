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
        // tech: 
            // find first & sec half of list 
                // can do so using fast & slow ptrs
            // then add each node from each halv accordingly 
        
        // time & space comp:
            // time: o(n) 
            // space: o(1)
        
        // 1. fast & slow ptr initialization 
        ListNode *fastPtr = head; 
        ListNode *slowPtr = head;

        // 2. find midPt 
            // by having right iterate til end 
            // but slowPtr will be one before the "midPt"
        while(fastPtr && fastPtr -> next)
        {
            // update ptrs 
            slowPtr = slowPtr -> next; 
            fastPtr = fastPtr -> next -> next;
        }

        // 3. have another ptr to hold start of our secHalf
        ListNode *startOfSec = slowPtr -> next; 

        // ensure you unlink slowPtr now.. want to split our linked list
            // splits end of first half from beg of first half
        slowPtr -> next = nullptr;

        // 4. start reversing everything
        ListNode *prevPtr = nullptr;
        while(startOfSec)
        {
            ListNode *tempNext = startOfSec -> next; 

            // start reversing 
            startOfSec -> next = prevPtr;
            prevPtr = startOfSec;
            startOfSec = tempNext; 
        }

        // 5. start adding things from each list

        ListNode *firstPtr = head;
        startOfSec = prevPtr; 
        while(startOfSec)
        {
            ListNode *tempNext1 = firstPtr -> next;;
            ListNode *tempNext2 = startOfSec -> next;

            firstPtr -> next = startOfSec; 
            startOfSec -> next = tempNext1; 

            firstPtr = tempNext1; 
            startOfSec = tempNext2; 
        }
    }
};