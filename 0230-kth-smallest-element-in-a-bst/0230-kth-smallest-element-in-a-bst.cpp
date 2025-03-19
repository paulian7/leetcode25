/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        // notes: bst 
            // everything left from root is < and...
            // everything right from root is >
        // tech: iterative depth first search & stack --> time comp: o(n)

        // 1. declare stack to keep track of traversing nodes
        stack<TreeNode*> travNode;

        // 2. declare / initialize pointer to track traversal
        TreeNode* currPtr = root;

        // 3. iterate through tree
        while(!travNode.empty() || currPtr != nullptr)
        {
            // try to go to the furthest left subtree as we can
            while(currPtr != nullptr)
            {
                // add curr node to stack first
                travNode.push(currPtr);
                // update curr node to our left subtree now as that's dfs
                currPtr = currPtr -> left; 
            }

            currPtr = travNode.top();
            // popping most recent value we added to our stack
            travNode.pop();
            k--;

            if(k == 0)
            {
                return currPtr -> val;
            }

            currPtr = currPtr -> right;
        }

        return -1;
    }
};