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

        // 1. dummyNode pointer to help us w/ edge cases
        ListNode *dummyNodePtr = new ListNode(-1);

        // 2. have a tailPtr point to the end of our new list
        ListNode *tailPtr = dummyNodePtr;

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

            // always ensure you're updating our tailPtr for next iteration
            tailPtr = tailPtr -> next; 
        }

        // 4. ensure all lists have been iterated thr 
        if(list1 != nullptr)
        {
            tailPtr -> next = list1; 
        }
        else if(list2 != nullptr)
        {
            tailPtr -> next = list2;
        }

        return dummyNodePtr -> next;
    }
};