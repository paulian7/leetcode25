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
        // tech: depth first search w/ recursion --> time comp: o(n)

        // 1. take care of base case 
            // when tree is empty --> so when root is NULL
        if(root == NULL)
        {
            return 0;
        }

        // 2. otherwise, perform recursive solution 
            // we'll have 1 + <-- accounts for root node depth of 1
            // then recursively call dfs on left and right subtrees
        return 1 + max(maxDepth(root -> left), maxDepth(root -> right));
    }
};