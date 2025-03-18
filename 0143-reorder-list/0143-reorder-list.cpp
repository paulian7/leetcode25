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
        // idea: 
            // take beginning of list and merging it w/ second half of list
            // second portion of list has to be reversed --> then merge accordingly
        
        // 1. find middle point of list (want to find first and second half of list)
            // declare and initialize our 2 pointers
        ListNode *slowPtr = head; 
        ListNode *fastPtr = head -> next; 

        // 2. iterate thr linked list to find middle point 
            // iterate til fastPtr hasn't reached end of list
        while((fastPtr != nullptr) && (fastPtr -> next != nullptr))
        {
            // update our pointers
            slowPtr = slowPtr -> next;
            fastPtr = fastPtr -> next -> next;
        }

        // 3. declare and initialize the beginning of the second half of our list
        ListNode *secondPtr = slowPtr -> next;
        // split the linked list now by setting the next of slowptr to nullptr
        slowPtr -> next = nullptr;

        // 4. reverse the second half of our linked list
        ListNode *preVal = nullptr;
        ListNode *tempVal = nullptr;
        while(secondPtr != nullptr) // REVERSING HAPPENS HERE ;-;
        {
            tempVal = secondPtr -> next;
            secondPtr -> next = preVal;
            preVal = secondPtr; 
            secondPtr = tempVal;
        }

        // 5. merge the 2 halves of our linked list
        ListNode *firstVal = head; // head of our first linked list
        secondPtr = preVal; // head of our second linked list

        while(secondPtr != nullptr)
        {
            ListNode *tempVal1 = firstVal -> next; 
            ListNode *tempVal2 = secondPtr -> next; 

            firstVal -> next = secondPtr; 
            secondPtr -> next = tempVal1; 

            firstVal = tempVal1; 
            secondPtr = tempVal2; 
        }
    } 
};