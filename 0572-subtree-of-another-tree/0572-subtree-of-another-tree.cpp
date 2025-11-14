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
                // m - num of nodes in subroot 
                // n - num of nodes in root 

        // 1. cover base cases 
            // when subroot is an empty tree --> so technically is a subroot of main tree
        if(!subRoot)
        {
            return true;
        }

        // when main tree is empty --> no
        if(!root)
        {
            return false;
        }

        // 2. check if root right off the bat matches up w/ the subtree
        if(sameTree(root, subRoot))
        {
            return true;
        }

        // 3. else, go search for "subRoot" in either left or right subtree of our main tree
        return isSubtree(root -> left, subRoot) || 
                isSubtree(root -> right, subRoot); 
    }

    // HELPER FUNCTION == 
    bool sameTree(TreeNode* root, TreeNode* subRoot) {
        // edge case -- dealing w/ empy trees --> ofc same 
        if(!root && !subRoot)
        {
            return true;
        }

        // edge case - when both trees aren't empty... check if values match up
        if((root && subRoot) && (root -> val == subRoot -> val))
        {
            // compare left && right subtrees now of root && subroot 
            return sameTree(root -> left, subRoot -> left) && 
                    sameTree(root -> right, subRoot -> right);
        }

        // else, return false.. like when one of the trees are nonempty 
        return false;
    }
};