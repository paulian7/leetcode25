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
            // space: o(n) 
                // balanced tree - o(n)
                // unbalanced tree - o(n)

        // 1. RECURSIVE DFS -- base case 
            // when there's no root 
        if(!root) 
        {
            return 0;
        }

        // 2. split into subproblems to perform recursive calls 
        return 1 + max(maxDepth(root -> left), maxDepth(root -> right));
    }
};