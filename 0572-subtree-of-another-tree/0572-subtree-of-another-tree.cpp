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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        // 1. cover base case 
        if(root == nullptr)
        {
            return false; 
        }

        // check if identical from the root (i.e from the start) 
        if(isIdentical(root, subRoot))
        {
            return true; 
        }

        // else, check further into the subtrees 
        return isSubtree(root -> left, subRoot) || isSubtree(root -> right, subRoot);
    }

    // create a helper function 
    bool isIdentical(TreeNode* node1, TreeNode* node2)
    {
        // 1. cover base cases 
            // empty node's :(  
        if((node1 == nullptr) || (node2 == nullptr))
        {
            return node1 == nullptr && node2 == nullptr;
        }

        // our recursive call starts here 
            // know both trees are nonempty, but need to check their subtrees too
        return node1 -> val == node2 -> val && isIdentical(node1 -> left, node2 -> left) && isIdentical(node1 -> right, node2 -> right);
    }
};