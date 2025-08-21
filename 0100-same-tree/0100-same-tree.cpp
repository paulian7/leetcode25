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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // tech: 
            // need SAME values AND same structure
            // depth first search -- 
                // very handy for recursion 
        
        // time & space comp: 
            // time: o(p + q)
                // worst case, need. to iterate thr every single node in both trees
            // space: o(n) 

        // 1. RECURSIVE - BASE CASE
            // empty trees technically equal
        if(!p && !q)
        {
            return true;
        }

        // 2. split problem up
        if(p && q && p -> val == q -> val)
        {
            // perform recursive call 
            return isSameTree(p -> left, q -> left) && isSameTree(p -> right, q -> right);
        }
        else 
        {
            return false;
        }
        
    }
};