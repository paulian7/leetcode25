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
        // tech: pointers 

        // time & space comp: 
            // time: o(n + m)
            // space: o(1)

        // 1. create a dummyPtr - helps us iterate thr our new merged list afterwards
        ListNode *dummyPtr = new ListNode(-1);

        // 2. have a pointer point to last node of our new list for now 
        ListNode *tailPtr = dummyPtr; 

        // 3. start iterating thr the 2 lists
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

            // always update tailPtr to prep for next iteration 
            tailPtr = tailPtr -> next; 
        }

        // 4. ensure we've iterated fully thr both lists
        if(list1 != nullptr)
        {
            tailPtr -> next = list1;
        }
        else 
        {
            tailPtr -> next = list2; 
        }

        // 5. return new merged list
        return dummyPtr -> next;
    }
};