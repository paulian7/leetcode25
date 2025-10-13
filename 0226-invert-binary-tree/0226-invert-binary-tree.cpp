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
        // tech: recursion w/ the basis of DFS 
            // DFS - depth first search 
                // traverse thr left THEN right subtree(s)
        
        // time & space comp: 
            // time: o(n)
            // space: o(n) 
        
        // 1. create base case for recursion 
        if(!root)
        {
            return nullptr; 
        }

        // 2. perform swap operation on our 2 children of our curr root node
        swap(root -> left, root -> right); 

        // 3. perform recursive calls on each subtree (left / right) 
        invertTree(root -> left); 
        invertTree(root -> right); 

        // 4. return the root of the newly inverted tree
        return root; 
    }
};