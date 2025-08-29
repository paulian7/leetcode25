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
        
        // 1. declare a dummyPtr to return our new merged list @ the end 
        ListNode *dummyPtr = new ListNode(0); 
        
        // 2. declare a tailPtr to track the end of our new list 
            // initialize to pt to where dummyPtr points to now 
                // (aka dummyNode) 
        ListNode *tailPtr = dummyPtr; 

        // 3. start merging the 2 lists accordingly 
        while((list1 != nullptr) && (list2 != nullptr))
        {
            // check which node from the 2 lists to add first 
            if(list1 -> val < list2 -> val)
            {
                // add node from list1 
                tailPtr -> next = list1; 

                // update list1's ptr to point to next node in its list 
                list1 = list1 -> next; 
            }
            else 
            {
                // add node from list2 instead 
                tailPtr -> next = list2; 

                // update list2's ptr 
                list2 = list2 -> next; 
            }

            // always ensure you're updating your tailPtr to...
                // .. the newest addition
            tailPtr = tailPtr -> next; 
        }

        // 4. ensure any remaining nodes are added to the list 
        if(list1 != nullptr)
        {
            // add any remaining nodes from list1 
            tailPtr -> next = list1; 
        }
        else 
        {
            // add any remaining nodes from list2
            tailPtr -> next = list2; 
        }

        // 5. AT THE VERY END, return the merged list by using...
            // .. dummyPtr to our advantage! 
        return dummyPtr -> next;
    }
};