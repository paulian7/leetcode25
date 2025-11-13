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
    // MAIN FUNCTION ===
    int minDepth(TreeNode* root) {
        // tech: recursive depth first search (dfs) 
        
        // time & space comp: 
            // time: o(n)
            // space: o(n)
        return dfs(root);
    }

    // HELPER FUNCTION == 
    int dfs(TreeNode* root) {
        // establish base case, as always w/ recursion technique
        if(!root)
        {
            return 0;
        }

        // 2. deal w/ edge cases -- if 1 of the childs are non-null, but the other is
        if(!root -> left)
        {
            // focus on other node 
            return 1 + dfs(root -> right); 
        }
        else if(!root -> right)
        {
            // focus on other node
            return 1 + dfs(root -> left);
        }

        // -- edge case of if both children do exist 
            // then want to take smallest of the two children 
        return 1 + min(dfs(root -> left), dfs(root -> right));
    }
};