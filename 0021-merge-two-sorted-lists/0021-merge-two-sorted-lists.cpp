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
        // tech: iterative approach --> time comp: o(n + m) 
        
        // 1. declare and initialize a dummy node
            // helps us avoid edge cases of an empty linked list 
        
        // dummyNodePtr points to the dummy node we created w/ val of -1
        ListNode *dummyNodePtr = new ListNode(-1); 

        // have a tailPtr point to last node in our linked list 
            // which is the dummyNode for now 
        ListNode *tailPtr = dummyNodePtr; 

        // 2. iterate thr the 2 lists and create a new merged list of the 2 
            // as long as both lists are non-empty 
        while((list1 != nullptr) && (list2 != nullptr))
        {
            // if l1 has smallest node so far
            if(list1 -> val < list2 -> val)
            {
                // add l1 val to end of tail 
                tailPtr -> next = list1; 
                // update l1 pointer 
                list1 = list1 -> next;
            }
            else 
            {
                tailPtr -> next = list2; 
                list2 = list2 -> next;
            }

            // always update tail ptr after adding a new node to our new linked list
            tailPtr = tailPtr -> next;
        }

        // 3. add any remaining nodes from any of the lists (if any)
        if(list1 != nullptr)
        {
            tailPtr -> next = list1; 
        }
        else 
        {
            tailPtr -> next = list2; 
        }

        // 4. returns next node after the dummyNode 
            // gives us the new merged linked list
        return dummyNodePtr -> next;
    }
};