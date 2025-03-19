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
    bool isValidBST(TreeNode* root) {
        // tech: depth first search --> time comp: o(n)

        // call recursive function - arguments are:
            // currNode, left boundary, right boundary
            // long_min is -infinity -> our left boundary 
            // long_max is +infinity -> our right boundary
             
        return isValid(root, LONG_MIN, LONG_MAX);
    }

private:
    // helper function 
    bool isValid(TreeNode* currNode, long left, long right)
    {
        if(!currNode)
        {
            return true;
        }

        if(!(left < currNode -> val && currNode -> val < right))
        {
            return false;
        }

        // checking subtrees now 
            // leftSubtree - leftSubTreeNode, leftBoundary, val (bc every val has to be less than parent val)
            // rightSubtree - 
        return (isValid(currNode -> left, left, currNode -> val) &&
                isValid(currNode -> right, currNode -> val, right));
    }
};