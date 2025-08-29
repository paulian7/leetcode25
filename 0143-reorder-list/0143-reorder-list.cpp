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
        // tech: reverse 2nd half of list, then merge accordingly 
            // establish 2nd half of list by FIRST finding fast & slow ptrs

        // time & space comp: 
            // time: o(n)
            // space: o(1)
        
        // 1. establish our slow & fast ptrs
        ListNode *slowPtr = head; 
        ListNode *fastPtr = head -> next; 

        // 2. move slowPtr to correct location (will be 1 node behind the "midPt")
        while((fastPtr != nullptr) && (fastPtr -> next != nullptr))
        {
            slowPtr = slowPtr -> next; 
            fastPtr = fastPtr -> next -> next; 
        }

        // 3. move slowPtr to "start of 2nd half of list"
        ListNode *secHalf = slowPtr -> next; 

        // 4. cut off ties btwn 1st and 2nd half of list 
        slowPtr -> next = nullptr; 

        // 5. set-up algo for reversing 2nd half of list 
        ListNode *prevPtr = nullptr; 
        while(secHalf != nullptr)
        {
            ListNode *tempNext = secHalf -> next; 

            // start reversing 
            secHalf -> next = prevPtr; 
            prevPtr = secHalf; 
            secHalf = tempNext; 
        }

        // 6. add nodes accordingly from each half now 
        ListNode *firstHalf = head; 
        ListNode *startSecHalf = prevPtr; 
        while(startSecHalf != nullptr)
        {
            ListNode *tempNext1 = firstHalf -> next; 
            ListNode *tempNext2 = startSecHalf -> next; 

            firstHalf -> next = startSecHalf; 
            startSecHalf -> next = tempNext1; 

            firstHalf = tempNext1; 
            startSecHalf = tempNext2;
        }
    }
};