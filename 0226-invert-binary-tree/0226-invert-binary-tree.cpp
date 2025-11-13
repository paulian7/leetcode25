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
    TreeNode* invertTree(TreeNode* root) {
        // tech: recursive depth first search (dfs) 
            // going thr left subtree(s) first then right subtree(s) 
        
        // time & space comp: 
            // time: o(n) 
                // iterating node by node 
            // space: o(n) 
                // o(n), worst case - unbalanced tree 
                // o(logn), best case - balanced tree 
        
        // 1. establish a base case - as you would w/ any recursive technique 
        if(!root)
        {
            return nullptr;
        }

        // 2. op - start swapping 
        swap(root -> left, root -> right);

        // 3. split overall problem - into subproblems -> just the left and right subtree(s)
        invertTree(root -> left); 
        invertTree(root -> right); 

        // 4. return completed invert tree 
        return root;
    }
};