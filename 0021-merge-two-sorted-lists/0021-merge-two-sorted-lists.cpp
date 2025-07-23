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
        // time & space comp: 
            // time: o(n + m)
            // space: o(1)

        // 1. create a dummy node 
        ListNode *dummyNodePtr = new ListNode(-1); 
        
        // 2. have a tailPtr pt to end of our new merged list
        ListNode *tailPtr = dummyNodePtr; 

        // 3. iterate thr 
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

        // 4. account for any remaining nodes 
        if(list1 != nullptr)
        {
            tailPtr -> next = list1; 
        }
        else 
        {
            tailPtr -> next = list2; 
        }

        return dummyNodePtr -> next; 
    }
};