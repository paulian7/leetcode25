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
        // 1. create dummyPtr 
        ListNode *dummyPtr = new ListNode(-1, head); 

        // 2. create our 2 pointers 
            // fast 
            // slow 
        ListNode *slowPtr = dummyPtr; 
        ListNode *fastPtr = head; 

        // 3. place our "fastPtr" into the right position 
        while(n > 0)
        {
            fastPtr = fastPtr -> next; 
            n -= 1; 
        }

        // 4. throw both pointers into action now 
            // ensuring that our slowPtr is in pos 
        while(fastPtr != nullptr)
        {
            fastPtr = fastPtr -> next;
            slowPtr = slowPtr -> next; 
        }

        // 5. finally do the removing 
        slowPtr -> next = slowPtr -> next -> next; 

        // 6. return our new linked list w/o that node now
        return dummyPtr -> next;
    }
};