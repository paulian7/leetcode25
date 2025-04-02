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
        // time comp: o(n), space comp: o(1)
            // finding first & second half 
                // can do so by using fast & slow ptrs 
            // then adding each node from the halves appropriately 
        
        // 1. declare & initialize our fast and slow ptrs 
        ListNode *fastPtr = head -> next; 
        ListNode *slowPtr = head; 

        // 2. find our midPt now (where we can half the array) 
        while(fastPtr != nullptr && fastPtr -> next != nullptr)
        {
            // update ptrs appropriately w/ each iteration 
            slowPtr = slowPtr -> next; 
            fastPtr = fastPtr -> next -> next;
        }

        // 3. reverse the second half of the array now 
        ListNode *startOfSecHalfPtr = slowPtr -> next; // gets beg of 2nd half of array
        // make sure to split the 2 arrays now (unlink) 
        slowPtr -> next = nullptr; 

        ListNode *prevVal = nullptr; 
        while(startOfSecHalfPtr != nullptr)
        {
            ListNode *tempNext = startOfSecHalfPtr -> next; 
            // actual reversing here 
            startOfSecHalfPtr -> next = prevVal; 
            prevVal = startOfSecHalfPtr; 
            startOfSecHalfPtr = tempNext; 
        }

        // 4. start building the reordered arrray now 
        ListNode *firstPtr = head; // start of 1st part 
        
        // have a pointer for the start of the 2nd part 
        startOfSecHalfPtr = prevVal; // prevVal holds start of 2nd list 
        while(startOfSecHalfPtr != nullptr)
        {
            // want to hold next node to traverse to in each of the lists 
            ListNode *temp1 = firstPtr -> next; 
            ListNode *temp2 = startOfSecHalfPtr -> next; 

            // reorder our pointers accordingly now 
            firstPtr -> next = startOfSecHalfPtr; 
            startOfSecHalfPtr -> next = temp1; 

            // update pointers now for next iteration 
            firstPtr = temp1; 
            startOfSecHalfPtr = temp2;   
        } 
    }
};