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
        // tech: performing depth first search --> time comp: o(n)

        // 1. check base case 
        if(root == NULL)
        {
            return NULL;
        }

        // 2. swap children of our curr node (aka root)
        TreeNode *tempNode = root -> left; 
        root -> left = root -> right;
        root -> right = tempNode;

        // 3. recursively invert the left and right subtrees
        invertTree(root -> left);
        invertTree(root -> right);

        // 4. return the inverted tree 
        return root;
    }
};