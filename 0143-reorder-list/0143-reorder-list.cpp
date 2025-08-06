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

        // 2. find our midPt now... where our array will be halved 
            // while fastPtr is valid && is NOT the last node in the list
        while(fastPtr != nullptr && fastPtr -> next != nullptr)
        {
            // move ptrs to correct spot 
            slowPtr = slowPtr -> next; 
            fastPtr = fastPtr -> next -> next;
        }

        // 3. reverse the second half of the array now! 
            // slowPtr will be ONE node behind our "midPt" 
            // startOfHalfPftr --> now becomes the start of the 2nd half of list 
        ListNode *startOfHalfPtr = slowPtr -> next; 

        // make sure to split the 2 arrays now (unlink!) 
        slowPtr -> next = nullptr; 

        // 4. start reversing the 2nd half of the list 
        ListNode *prevPtr = nullptr; 
        while(startOfHalfPtr != nullptr)
        {
            ListNode *tempNext = startOfHalfPtr -> next; 

            // start reversing 
            startOfHalfPtr -> next = prevPtr; 
            prevPtr = startOfHalfPtr;
            startOfHalfPtr = tempNext; 
        }

        // 5. start building reordered linked list
            // firstPtr - points to our starting node (aka from the 1st half) 
        ListNode *firstPtr = head; 

        // have another ptr that points to the start of the sec half 
            // (aka prevPtr - hold start of sec half)
        startOfHalfPtr = prevPtr; 
        while(startOfHalfPtr != nullptr)
        {
            // want to hold tempVals for next node to go to 
            ListNode *tempNext1 = firstPtr -> next; 
            ListNode *tempNext2 = startOfHalfPtr -> next; 

            // reorder pointers accordingly NOW
            firstPtr -> next = startOfHalfPtr; 
            startOfHalfPtr -> next = tempNext1; 

            // update ptrs for next iteration 
            firstPtr = tempNext1; 
            startOfHalfPtr = tempNext2;
        }
    }
};