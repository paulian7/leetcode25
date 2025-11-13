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
            // space: o(n) 
                // o(n) - unbalanced tree 
                // o(logn) - best case, balanced tree
        
        // 1. start w/ base case as always w/ recursion 
            // base case - empty trees = tech equal :) 
        if(!p && !q)
        {
            return true;
        }

        // 2. else, split problem into subproblems
        if((p && q) && (p -> val == q -> val))
        {
            // perform recursive call!...
                // on left subtree of p && q 
                // then on right subtree of p && q 
            return isSameTree(p -> left, q -> left) && isSameTree(p -> right, q -> right);
        }
        else 
        {
            return false;
        }
    }
};