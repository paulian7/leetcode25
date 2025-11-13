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
            // where you traverse thr all the left subtrees first -> then right substrees
        
        // time & space comp:
            // time: o(n), iterating thr each node 
            // space: o(n), in the case we're dealing w/ an unbalanced tree 
                // where all nodes happen to fall in the left substree only - for example
                // tree being left / right skewed 
        
        // 1. declare base case as always w/ recursion 
            // check to see if we have a tree to iterate thr
        if(!root)
        {
            return nullptr;
        }

        // 2. otherwise, perform swap operation on curr root's children 
            // swap() -- takes o(1) time 
        swap(root -> left, root -> right); 

        // 3. perform recursive calls on each substree respectively
            // go left substree -> then right subtree
        invertTree(root -> left); 
        invertTree(root -> right);

        // 4. return new inverted tree now by returning the root 
        return root;
    }
};