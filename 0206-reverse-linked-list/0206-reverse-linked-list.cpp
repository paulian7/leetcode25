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
    ListNode* reverseList(ListNode* head) {
        // approach - 2 pointers --> time comp: o(n) 
            // iterating thr linked list and reversing pointers 

        // 1. initialize our 2 pointers
        ListNode *prev = nullptr;
        ListNode *curr = head; 

        // 2. iterate thr linked list... reversing pointers
        while(curr != nullptr)
        {
            // create a temp var to hold next node to reverse ptrs 
            ListNode *tempNext = curr -> next; 

            // REVERSING STEPS! 
            curr -> next = prev; 
            prev = curr; 
            curr = tempNext; 
        }

        // 3. returned our reversed linked list 
            // as curr will now be nullptr 
            // prev is now our new head! 
        return prev;
    }
};