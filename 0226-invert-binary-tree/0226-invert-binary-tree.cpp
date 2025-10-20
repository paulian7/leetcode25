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
        // tech: recursion && depth first search (dfs) 
            // dfs - traversing thr left -> then right subtree(s)

        // time & space comp: 
            // time: o(n) - goin thr each node 
            // space: o(n) - for recursion stack
        
        // 1. declare base case for recursion 
        if(!root)
        {
            return nullptr;  
        }

        // 2. otherwise, perform swap operation on children 
            // takes o(1) time 
        swap(root -> left, root -> right); 

        // 3. perform recursive calls on each subtree respectively (left, then right) 
        invertTree(root -> left); 
        invertTree(root -> right); 

        // 4. return new inverted tree by returning root 
        return root;
    }
};