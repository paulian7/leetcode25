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
        // tech: 
            // want to return max depth (aka longest path from root to leaf)
            // 3 ways to solve -- 
                // recursive dfs 
                    // time: o(n) 
                    // space: o(h) - h = height of tree 
                        // worst case - o(n) if not balanced binary tree 
                // iterative dfs (stack) 
                // breadth first search.. bfs
        
        // 1. RECURISVE DFS -- establish base case 
        if(root == nullptr)
        {
            return 0;
        }

        // 2. split into subproblems 
        return 1 + max(maxDepth(root -> left), maxDepth(root -> right));
    }
};