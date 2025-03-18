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
        // approach: 2 pointers + using a dummy node --> time comp: o(n) 

        // 1. declare / initialize a dummy node 
            // let's us update the appropriate pointer of the node...
            // ... not just the node we're removing 
        ListNode *dummyNode = new ListNode(0); // holds val of 0 for now 
        
        // set dummy node's next pointer to the head 
        dummyNode -> next = head; 

        // 2. declare and initialize our 2 pointers 
        ListNode *leftPtr = dummyNode; 
        ListNode *rightPtr = head; // have it set initially to head 

        // 3. place rightPtr at the correct spot before iterating...
            // ... to find our node to update its ptrs (before removing node)
            while(n > 0 && rightPtr != nullptr) 
            {
                rightPtr = rightPtr -> next; 
                // once n hits 0, we shifted the rightPtr to the place we want
                n  -= 1;
            }

        // 4, iterate and update ptrs til rightPtr hits end of list
        while(rightPtr != nullptr)
        {
            leftPtr = leftPtr -> next; 
            rightPtr = rightPtr -> next; 
        }

        // 5. NOW update the ptrs and finally delete the nth node 
        
        // update left node's ptrs 
        leftPtr -> next = leftPtr -> next -> next;

        // returns our linked list w/o our dummy node :)
        return dummyNode -> next; 
    }
};