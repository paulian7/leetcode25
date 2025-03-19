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
        // DEPTH FIRST SEARCH RECURSIVE SOLUTION --
        
        // 1. take care of base case 
            // (when tree is empty... so when root is NULL)
        if(root == NULL)
        {
            return 0; 
        }

        // 2. otherwise, perform recursive solution 
            // 1 (accounts for depth of root node) 
            // performing depth first search strategy (DFS) here 
        return 1 + max(maxDepth(root -> left), maxDepth(root -> right));
    }
};