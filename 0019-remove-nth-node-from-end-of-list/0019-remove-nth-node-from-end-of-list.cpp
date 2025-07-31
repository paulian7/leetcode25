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
            // create dummy node w/ dummy val of 0 
            // have next ptr point to HEAD
        ListNode *dummyPtr = new ListNode(0, head);

        // 2. have left & rightPtrs 
            // rightPtr - acts as our fastPtr, but default its val to HEAD for now
        ListNode *leftPtr = dummyPtr;
        ListNode *rightPtr = head; 

        // 3. place rightPtr @ correct spot to prepare 
            // rightPtr will be 1 node BEHIND the node we need to remove after this while()
        while(n > 0)
        {
            rightPtr = rightPtr -> next;
            n -= 1;
        }

        // 4. utilize the 2 of our pointers now til rightPtr reaches end 
            // this will help us pos leftPtr in the corr spot to do the removal next 
        while(rightPtr != nullptr)
        {
            leftPtr = leftPtr -> next; 
            rightPtr = rightPtr -> next;
        }

        // 5. do the REMOVAL of the nth node now
            // NOW that leftPtr is the correct spot
            // leftPtr is curr RIGHT BEHIND the node we need to remove 
        leftPtr -> next = leftPtr -> next -> next; 

        // 6. return corrected linked list w/o the node 
        return dummyPtr -> next;
    }
};