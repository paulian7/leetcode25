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
        // 1. cover edge cases 
        if(!subRoot)
        {
            return true;
        }

        if(!root)
        {
            return false;
        }

        // check if root matches up w/ subroot currently 
        if(sameTree(root, subRoot))
        {
            return true;
        }

        // else, perofrm recursive calls on the left and right subtrees to see if subtree is in there
        return isSubtree(root -> left, subRoot) || 
            isSubtree(root -> right, subRoot);
    }
    
    bool sameTree(TreeNode* root, TreeNode* subRoot) {
        // base case 
        if(!root && !subRoot)
        {
            return true;
        }

        // actually check 
        if((root && subRoot) && (root -> val == subRoot -> val))
        {
            return sameTree(root -> left, subRoot -> left) && 
                sameTree(root -> right, subRoot -> right);
        }
        else 
        {
            return false;
        }
    }
};