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
        // tech: splitting list, reversing 2nd half of list, then making new list

        // time & space comp: 
            // time: o(n)
            // space: o(1) 

        // 1. declare our fast & slow ptrs 
        ListNode *fastPtr = head; 
        ListNode *slowPtr = head; 

        // 2. move slowPtr to midPt 
        while(fastPtr && fastPtr -> next)
        {
            fastPtr = fastPtr -> next -> next; 
            slowPtr = slowPtr -> next; 
        }

        // 3. w/ slowPtr finally at its midPt, start reversing 2nd half of lsit
        ListNode *prev = nullptr; 
        ListNode *curr = slowPtr -> next;
        slowPtr -> next = nullptr; 

        while(curr != nullptr)
        {
            ListNode *tempNext = curr -> next; 
            curr -> next = prev; 
            prev = curr; 
            curr = tempNext; 
        }


        // 4. add nodes in accordingly from both halves
        ListNode *startHalf = head; 
        ListNode *secHalf = prev;

        while(secHalf != nullptr)
        {
            ListNode *tempNext1 = startHalf -> next; 
            ListNode *tempNext2 = secHalf -> next; 

            startHalf -> next = secHalf;
            secHalf -> next = tempNext1; 

            // update pointers 
            startHalf = tempNext1;
            secHalf = tempNext2;
        }
    }
};