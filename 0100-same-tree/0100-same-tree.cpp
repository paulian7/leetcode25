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
        // tech: recursive depth first search 

        // time & space comp: 
            // time: o(p + q) 
            // space: o(n)
        
        // 1. base cases
        if(!p && !q)
        {
            return true;
        }

        // 2. check for equivalance 
        if((p && q) && (p -> val == q -> val))
        {
            return isSameTree(p -> left, q -> left) && 
                isSameTree(p -> right, q -> right);
        }

        // not the same structure 
        return false;
    }
};