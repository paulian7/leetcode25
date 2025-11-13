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
    // MAIN FUNCTION == 
    int minDepth(TreeNode* root) {
        // tech: recursive depth first search (dfs) 

        // time & space comp: 
            // time: o(n)
            // space: o(n)
        
        return dfs(root);
    }

    // HELPER FUNCTION ==
    int dfs(TreeNode* root) {
        // 1. establish base case 
        if(!root)
        {
            return 0;
        }

        // 2. deal w/ edge cases now -- if 1 of the childs are non-null
        if(!root -> left)
        {
            // if left child of root is NULL --> return 1 + min depth for right child of root node
            return 1 + dfs(root -> right);
        }
        else if(!root -> right)
        {
            // if right child of root is NULL...
            return 1 + dfs(root -> left);
        }

        // if both children exist --
        return 1 + min(dfs(root -> left), dfs(root -> right));
    }
};