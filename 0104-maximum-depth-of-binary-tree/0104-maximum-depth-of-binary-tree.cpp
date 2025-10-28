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
    int maxDepth(TreeNode* root) {
        // tech: 2 possible ways 
            // recursive dfs -- X 
            // iterative bfs 
        
        // time & space comp: 
            // time: o(n)
                // visiting each node exactly once 
                // n -- number of nodes
            // space: o(logn)
                // worst case, tree is unbalanced (ex -- each node only having a left child node)
                    // storage to keep call stack will be o(n) 
                // best case, tree is balanced! -- height of tree will be log(n) 
        
        // 1. establish a base case for recursive dfs 
            // base case - when we have no tree (aka no root node present) 
        if(!root)
        {
            return 0;
        }

        // 2. split our overall problem into subproblems --> to put recursive calls into action --> gets result
            // 1 + 
                // accounts for our root node 
            // max(depthOfLeftSubTree, depthOfRightSubTree);
                // holds maximum length from either left or right subtree 
        return 1 + max(maxDepth(root -> left), maxDepth(root -> right));
    }
};