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
    // MAIN FUNCTION
        // tech: depth first search w/ recursion 

    // time & space comp: 
        // time: o(n)
        // space: o(n) -- space required being the recursive call stack space 
            // max num of active stack calls == max depth of tree ==> could equal total # of nodes in tree
    int minDepth(TreeNode* root) {
        return dfs(root);
    }

    // HELPER FUNCTION
    int dfs(TreeNode* root) {
        // 1. establish base case 
        if(!root)
        {
            return 0;
        }

        // 2. deal w/ EDGE CASE -- if 1 of the childs are non-null
        if(!root -> left)
        {
            return 1 + dfs(root -> right); 
        }
        else if(!root -> right)
        {
            return 1 + dfs(root -> left);
        }

        // 3. deal w/ OTHER edge case -- if both childs are non-null
        return 1 + min(dfs(root -> left), dfs(root -> right));
    }
};