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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // tech: iterative 

        // time & space comp: 
            // time: o(n) 
            // space: o(1) 
        
        // 1. establish a dummyPtr 
            // will help us return the entirity of new list 
        ListNode *dummyPtr = new ListNode(0); 

        // 2. establish a tailPtr 
            // will pt to end of our new linked list 
            // will pt to where dummyPtr pts to for now 
                // (aka dummyNode) 
        ListNode *tailPtr = dummyPtr; 

        // 3. start adding nodes accordingly 
        while((list1 != nullptr) && (list2 != nullptr))
        {
            if(list1 -> val < list2 -> val)
            {
                tailPtr -> next = list1; 
                list1 = list1 -> next; 
            }
            else 
            {
                tailPtr -> next = list2; 
                list2 = list2 -> next; 
            }

            tailPtr = tailPtr -> next; 
        }

        if(list1 != nullptr)
        {
            tailPtr -> next = list1; 
        }
        else 
        {
            tailPtr -> next = list2; 
        }

        return dummyPtr -> next;
    }
};