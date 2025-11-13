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
        // tech: recursive depth first search (dfs) 
            // need same vals && structure 
        
        // time & space comp: 
            // time: o(p + q) 
                // p - num of nodes in 'p' tree 
                // q - num of nodes in 'q' tree 
            // space: o(n) -- mainly comes from our call stack that's used during recursion techniques 
                // o(n) - due to unbalanced tree, worst case 
                    // n -- number of items in our call stack 
                // o(logn) - balanced tree, best case 
        
        // 1. start w/ a base case as always w/ recursion 
            // base case - is when we have an empty tree --> meaning tech equal 
        if(!p && !q)
        {
            return true;
        }

        // 2. else, do operation -- check for equivalance --> then split into subproblems
        if((p && q) && (p -> val == q -> val))
        {
            // perform recursive calls -- 
                // on left subtree of p && q 
                // on right subtree of p && q 
            return isSameTree(p -> left, q -> left) && 
                    isSameTree(p -> right, q -> right);
        }
        else 
        {
            return false; // no matching vals
        }
    }
};