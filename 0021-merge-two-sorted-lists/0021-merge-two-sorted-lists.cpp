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
        // tech: iterative approach 

        // time & space comp: 
            // time: o(n + m), n and m being lengths of the 2 resp lists 
        
        // 1. declare and initialize a dummy node 
            // helps us avoid edge cases of an empty linked list 
            // dummyNodePtr points to the dummy node we created w/ a val of -1 
        ListNode *dummyNodePtr = new ListNode(-1); 

        // have a tailPtr point to the last node in our linked list 
            // which is the dummy node for now 
        ListNode *tailPtr = dummyNodePtr; 

        // 2. iterate thr the 2 lists and create a new merged list of the 2 
            // as long as both lists are nonempty 
        while((list1 != nullptr) && (list2 != nullptr))
        {
            if(list1 -> val < list2 -> val)
            {
                // add l1 val to end of tail 
                tailPtr -> next = list1; 

                // update l1 ptr 
                list1 = list1 -> next; 
            }
            else 
            {
                // add l2 val to end of tail 
                tailPtr -> next = list2; 

                // update l2 ptr 
                list2 = list2 -> next; 
            }

            // always ensure you're updating tailPtr after new addition of a node 
            tailPtr = tailPtr -> next; 
        }

        // 3. add any remaining nodes from the lists (if any) 
        if(list1 != nullptr)
        {
            tailPtr -> next = list1; 
        }
        else 
        {
            tailPtr -> next = list2; 
        }

        // 4. return next node after the dummyNode 
            // which gives us our new merged list 
        return dummyNodePtr -> next; 
    }
};