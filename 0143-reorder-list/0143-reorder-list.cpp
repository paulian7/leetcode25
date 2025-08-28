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
        // time & space comp: 
            // time: o(n)
            // space: o(1) 

        // 1. want to find midPt 
        ListNode *slowPtr = head; 
        ListNode *fastPtr = head;

        // 2. want to place slowPtr in the corr spot 
        while(fastPtr && fastPtr -> next)
        {
            // update our pointers 
            slowPtr = slowPtr -> next; 
            fastPtr = fastPtr -> next -> next; 
        }

        // 3. from here, slowPtr should @ midPt, start reversing 2nd half of list
        ListNode *prev = nullptr; 
        ListNode *curr = slowPtr; 
        while(curr != nullptr) 
        {
            ListNode *tempNext = curr -> next; 

            curr -> next = prev;
            prev = curr;
            curr = tempNext; 
        }

        // 4. start adding each node corr from its resp halve 
        ListNode *startHalf = head; 
        ListNode *endHalf = prev; 
        while(endHalf -> next != nullptr)
        {
            ListNode *tempNext1 = startHalf -> next; 
            ListNode *tempNext2 = endHalf -> next; 

            startHalf -> next = endHalf; 
            endHalf -> next = tempNext1; 

            startHalf = tempNext1;
            endHalf = tempNext2;
        }
    }
};