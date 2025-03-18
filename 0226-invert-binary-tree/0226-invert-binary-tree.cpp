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
        // solution:
            // everytime we visit a node, take a look at its children and swap their positions 
            // recursively then run the function on both left and right subtrees
            // want to use depth first search here 

        // 1. check base case 
        if(root == NULL)
        {
            return NULL;
        }

        // 2. swap children of our current node 
        // use temp val to hold left's value 
        TreeNode *tempNode = root -> left; 
        // swap 
        root -> left = root -> right;
        root -> right = tempNode; 

        // 3. recursively invert the subtrees now 
        invertTree(root -> left); 
        invertTree(root -> right); 

        return root; 
    }
};