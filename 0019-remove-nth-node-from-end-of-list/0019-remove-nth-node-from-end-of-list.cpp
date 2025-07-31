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
        // tech: 2 pointers!! 

        // time & space comp:
            // time: o(n) 
            // space: o(1)

        // 1. create dummyNode && have ptr point to it
            // create dummy node w/ dummy val of 0
            // have next ptr point to HEAD
        ListNode *dummyPtr = new ListNode(0, head);

        // 2. have left & rightPtrs 
            // rightPtr - acts as our fast ptr.. but default val to HEAD for now
        ListNode *leftPtr = dummyPtr; 
        ListNode *rightPtr = head; 

        // 3. place rightPtr @ correct spot to prepare 
            // rightPtr is 1 node BEHIND the node we need to remove
        while(n > 0)
        {
            rightPtr = rightPtr -> next; 
            n -= 1; 
        }

        // 4. perform 2 pointers method now til rightPtr reaches end
            // helps us position leftPtr in the correct spot to do the removal
        while(rightPtr != nullptr)
        {
            leftPtr = leftPtr -> next; 
            rightPtr = rightPtr -> next;
        }

        // 5. do the removal of the n'th node now 
            // now that leftPtr is in the correct spot 
            // leftPtr is node RIGHT BEHIND the node we need to remove
        leftPtr -> next = leftPtr -> next -> next; 
        
        // 6. return corrected linked list w/o the node 
        return dummyPtr -> next; 
    }
};