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
            // find first & second half of list
                // can do so using fast & slow ptrs 
            // then adding each node from the halves accord 
        
        // time & space comp: 
            // time: o(n)
            // space: o(1) 
        
        // 1. declare & initialize our fast & slow ptrs 
            // default to head first 
        ListNode *fastPtr = head; // will go x2 later
        ListNode *slowPtr = head; // will go x1 later
        
        // 2. find our midPt now.. where our array will be halved 
            // while fastPtr is valid && NOT the last node in the list 
        while(fastPtr != nullptr && fastPtr -> next != nullptr)
        {
            // move ptrs to corr spot 
            slowPtr = slowPtr -> next; 
            fastPtr = fastPtr -> next -> next; 
        }

        // 4. reverse the second half of the array now 
            // slowPtr is curr ONE node behind our "midPt" 
            // startOfHalfPtr -->
                // once we do slowPtr -> next... this will become start of...
                // ... 2nd half of list
        ListNode *startOfSecHalfPtr = slowPtr -> next;

        // make sure to split the 2 arrays now -- unlink!
        slowPtr -> next = nullptr; 
        
        // 4. start reversing the 2nd half of the list
        ListNode *prevPtr = nullptr; 
        while(startOfSecHalfPtr != nullptr)
        {
            ListNode *tempNext = startOfSecHalfPtr -> next; 

            // start reversing 
            startOfSecHalfPtr -> next = prevPtr;
            prevPtr = startOfSecHalfPtr; 
            startOfSecHalfPtr = tempNext;
        }

        // 5. start building reordered linked list 
            // firstPtr - points to our starting node (from 1st half of list)
        ListNode *firstPtr = head;

        // reinitialize ptrs that pts to the start of the secHalf
        startOfSecHalfPtr = prevPtr;
        while(startOfSecHalfPtr != nullptr)
        {
            // want to hold tempVals for next node to go to 
            ListNode *tempNext1 = firstPtr -> next; 
            ListNode *tempNext2 = startOfSecHalfPtr -> next; 

            // reorder pointers accord NOW 
            firstPtr -> next = startOfSecHalfPtr; 
            startOfSecHalfPtr -> next = tempNext1; 

            // update ptrs for next iteration 
            firstPtr = tempNext1; 
            startOfSecHalfPtr = tempNext2;
        }
    }
};