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
        // time & space comp: 
            // time: o(n)
            // space: o(1)

        ListNode *curr = head; 
        ListNode *prev = nullptr; 

        while(curr != nullptr)
        {
            ListNode *tempNext = curr -> next; 

            curr -> next = prev; 
            prev = curr; 
            curr = tempNext; 
        }

        return prev; 
    }
};