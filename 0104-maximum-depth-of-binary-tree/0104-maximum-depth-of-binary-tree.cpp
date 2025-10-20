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
    int maxDepth(TreeNode* root) {
        // tech: depth first search (dfs) && recursion 

        // time & space comp: 
            // time: o(n) 
            // space: o(n), in worst case of having an unbalanced tree 
                // o(logn) - otherwise if balanced tree
        
        // 1. declare base case for recursion 
        if(!root)
        {
            return 0;
        }

        // 2. perform recursive calls 
        return 1 + max(maxDepth(root -> left), maxDepth(root -> right));
    }
};