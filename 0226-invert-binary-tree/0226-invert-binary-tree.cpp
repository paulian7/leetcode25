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
        // tech: breadth first search && recursion 

        // time & space comp:
            // time: o(n)
            // space: o(n) 
        
        // 1. establish base case for recursion 
        if(!root)
        {
            return nullptr; 
        }

        // 2. otherwise, perform swap() operation 
            // takes constant time 
        swap(root -> left, root -> right); 

        // 3. perform recursive calls on left and right subtree 
        invertTree(root -> left); 
        invertTree(root -> right);

        // 4. return completed inverted tree 
        return root;
    }
};