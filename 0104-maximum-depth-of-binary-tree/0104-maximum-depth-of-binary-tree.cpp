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
        // tech: bfs && recursion 

        // time & space comp: o(n)
            // IF dealing w/ balanced tree -> space is o(logn), o(n) if unbalanced

        // 1. establish base case
        if(!root)
        {
            return 0;
        }

        // 2. perform recursive calls on each respective subtree
        return 1 + max(maxDepth(root -> left), maxDepth(root -> right));
    }
};