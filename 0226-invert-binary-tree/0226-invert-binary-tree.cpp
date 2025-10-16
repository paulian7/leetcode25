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
            // DFS - depth first search... 
                // where we traverse thr left THEN right subtree(s) 

        // time & space comp: 
            // time: o(n)
            // space: o(n) -- for recursion stack
        
        // 1. create base case for recursion 
        if(!root) 
        {
            return nullptr;
        }

        // 2. otherwise, perform swap op (takes o(1) time) on first set of children
        swap(root -> left, root -> right); 

        // 3. NOW, perform recursive calls on each subtree (left && right)
            // DFS - rmbr goes thr left, then right subtree 
        invertTree(root -> left); 
        invertTree(root -> right);

        // 4. return new inverted tree by returning root 
        return root;
    }
};