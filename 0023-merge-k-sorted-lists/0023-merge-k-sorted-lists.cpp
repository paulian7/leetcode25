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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // time comp: o(nlogk)
            // how many times can we take the "k" lists and divide...
            // ... them by 2? --> gives o(logk) 
            // o(n) comes from going through each chunk...
            // ... after the division and ordering them accordingly
                // n is the number of nodes across all lists
        
        // 1. handle edge cases - if list is empty
        if(lists.empty())
        {
            return nullptr;
        }

        // 2. taking node pairs from the linked lists and merging them each time
            // keep doing until there'so nly 1 linked list remaining
            // (i.e our output linked list) 
        while(lists.size() > 1)
        {
            // want to keep reducing the length by cutting it in half
            
            // create a new linked list called mergedLists
            vector<ListNode*> mergedLists;

            // merging 2 lists at a time w/ the mergeList helper function
            for(int i = 0; i < lists.size(); i += 2)
            {
                ListNode* l1 = lists[i]; 
                // checking whether or not list 2 is in bounds, if not, we initialize l2 to nullptr
                ListNode* l2 = (i + 1 < lists.size()) ? lists[i + 1] : nullptr;
                mergedLists.push_back(mergeList(l1, l2));
            }

            lists = mergedLists;
        }

        // returns the final merged list
        return lists[0]; 
    }
private: 
    // helper function 
    ListNode* mergeList(ListNode* l1, ListNode* l2) {
        ListNode dummy; 
        ListNode *tail = &dummy; 

        while(l1 && l2) 
        {
            if(l1 -> val < l2 -> val)
            {
                tail -> next = l1; 
                l1 = l1 -> next; 
            }
            else 
            {
                tail -> next = l2; 
                l2 = l2 -> next; 
            }

            tail = tail -> next; 
        }

        if(l1)
        {
            tail -> next = l1; 
        }
        if(l2) 
        {
            tail -> next = l2; 
        }

        return dummy.next;
    }
};