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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // tech: 2 pointers && dummyNode trick 

        // time & space comp: 
            // time: o(n) 
            // space: o(1) 
        
        // 1. create dummyNode && have ptr point to it 
            // creating dummyNode w/ dummy val of 0 
            // have its next ptr point to HEAD
        ListNode *dummyPtr = new ListNode(0, head); 

        // 2. have left & rightPtrs 
            // rightPtr - acts as our fastPtr - but default its val to HEAD for now
            // leftPtr - will lag behind & pt to nullptr for now
        ListNode *leftPtr = dummyPtr; 
        ListNode *rightPtr = head;

        // 3. place rightPtr & corr spot to prepare 
            // rightPtr will be 1 node BEHIND the node we need to remove...
                // .. after this while() 
        while(n > 0)
        {
            rightPtr = rightPtr -> next; 
            n -= 1; 
        }

        // 4. utilize the 2 of our ptrs til rightPtr reaches end 
            // will pos leftPtr to corr spot to do the removal 
        while(rightPtr != nullptr)
        {
            leftPtr = leftPtr -> next; 
            rightPtr = rightPtr -> next; 
        }

        // 5. DO the REMOVAL of the nth node NOW
            // NOW... that the leftPtr is in the corr spot 
            // leftPtr is currently RIGHT BEHIND THE node we need to remove 
        leftPtr -> next = leftPtr -> next -> next;

        // 6. use dummyPtr -> next to return corr list w/o the nth node
        return dummyPtr -> next;
    }
};