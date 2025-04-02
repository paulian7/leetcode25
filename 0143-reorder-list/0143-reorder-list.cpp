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
        // time comp: o(n); space comp: o(1) 
            // finding first and second chunk
                // using fast and slow pointers
            // then adding each node within the chunks respectively
        
        // 1. initialize our fast and slow pointers
        ListNode *slowPtr = head; 
        ListNode *fastPtr = head;

        // 2. identify the middle part of array
            // once fastPtr reaches last node / nullptr...
            // slowPtr will be @ the middle part
        while(fastPtr != nullptr && fastPtr -> next != nullptr)
        {
            slowPtr = slowPtr -> next; // slow - shift by 1 
            fastPtr = fastPtr -> next -> next; // fast - shift by 2
        }

        // 3. start the reordering w/ all the ptrs :(
        ListNode *secondPtr = slowPtr -> next; // pts to the beginning of the second half of our list
        // as we're splitting the linked list (1st part & 2nd part)
        slowPtr -> next = nullptr; 

        // 4. reverse now the second half of our list 
        ListNode *preVal = nullptr;
        while(secondPtr != nullptr)
        {
            // temp val to track next node to reverse 
            ListNode *tempPtr = secondPtr -> next; 
            secondPtr -> next = preVal;
            preVal = secondPtr;
            secondPtr = tempPtr; 
        }

        // 5. start building the reordered array now 
        ListNode *firstPtr = head; // start of 1st part 
        // initialize ptr to prevPtr bc prevPtr holds last val looked at
            // secondPtr would've initially been nullptr if not reinitialized
        secondPtr = preVal; 
        while(secondPtr != nullptr)
        {
            ListNode *temp1 = firstPtr -> next; 
            ListNode *temp2 = secondPtr -> next; 

            // reorder pointers now
            firstPtr -> next = secondPtr;
            secondPtr -> next = temp1; 

            firstPtr = temp1; 
            secondPtr = temp2;
        }
    }
};