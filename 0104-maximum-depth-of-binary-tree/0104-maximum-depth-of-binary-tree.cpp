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
        // tech: binary tree -> recursive depth first search (dfs) 

        // time & space comp: 
            // time: o(n)
            // space: o(n)
                // balanced tree - o(n)
                // unbalanced tree - o(n)
        
        // 1. establish a base case for recursion 
            // when there's no root 
        if(!root)
        {
            return 0; 
        }

        // 2. split into subproblems to perform recursive calls on left && right subtrees 
        return 1 + max(maxDepth(root -> left), maxDepth(root -> right));
    }
};