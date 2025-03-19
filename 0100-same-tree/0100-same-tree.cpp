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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // tech: depth first search & recursion --> time comp: o(n) 

        // 1. cover cases - if both trees empty
        if(!p && !q)
        {
            return true; // as empty ofc the same
        }

        // if one of the trees are empty
        if(!p || !q)
        {
            return false; // got to be exactly the same 
        }

        // if vals don't match up
        if(p -> val != q -> val)
        {
            return false;
        }

        // 2. finally perform the recursive calls on the subtrees
        return isSameTree(p -> left, q -> left) && isSameTree(p -> right, q -> right);
    }
};