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
        // tech: recursive depth first search (dfs) 

        // time & space comp: 
            // time: o(m * n)
            // space: o(m + n)
                // m - num of nodes in subRoot 
                // n - num of nodes in root 
        
        // 1. deal w/ edge cases 
        // == when subRoot is empty --> technically subtree yes
        if(!subRoot)
        {
            return true;
        }

        // == when root is empty --> no
        if(!root)
        {
            return false;
        }

        // 2. check if root's subtree = subRoot 
        if(sameTree(root, subRoot))
        {
            return true;
        }

        // 3. else, check for subRoot in either left or right subtree of root 
        return isSubtree(root -> left, subRoot) || 
                isSubtree(root -> right, subRoot); 
    }

    // helper function 
    bool sameTree(TreeNode* root, TreeNode* subRoot) {
        // dealing w/ empty trees -> subtrees yes
        if(!root && !subRoot)
        {
            return true;
        }

        // when both trees aren't empty && vals of both are the same
        if(root && subRoot && root -> val == subRoot -> val)
        {
            // continue comparing the rest of the subtrees now if they're ==
            return sameTree(root -> left, subRoot -> left) && 
                    sameTree(root -> right, subRoot -> right);
        }

        // when one of the trees are nonempty
        return false;
    }
};