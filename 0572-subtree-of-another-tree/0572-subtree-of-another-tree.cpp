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
        // tech: recursion & helper functions 

        // time & space comp: 
            // time: o(m * n)
                // m -- number of nodes in subRoot 
                // n -- number of nodes in root 
            // space: o(m + n)

        // 1. w/ recursion, start off by covering BASE CASE 
        if(root == nullptr)
        {
            return false;
        }

        // 2. checking if identical from the start (aka root)
            // helper function comes into play here!
        if(isIdentical(root, subRoot))
        {
            return true;
        }

        // 3. isn't identical from the start, so check subtrees w/ the use of recursive calls
            // check if subtree is found in LEFT SUBTREE
            // check if subtree is found in RIGHT SUBTREE
        return isSubtree(root -> left, subRoot) || isSubtree(root -> right, subRoot);
    }

private: 
    // HELPER FUNCTION -- checks whether or not 2 nodes in question are similar 
    bool isIdentical(TreeNode *node1, TreeNode *node2) 
    {
        // 1. cover base case -- bc this too is a recursive function 
        if(!node1 || !node2)
        {
            return node1 == nullptr && node2 == nullptr;
        }

        // 2. otherwise, perform recursive 
        return node1 -> val == node2 -> val && isIdentical(node1 -> left, node2 -> left) && isIdentical(node1 -> right, node2 -> right);
    }
};