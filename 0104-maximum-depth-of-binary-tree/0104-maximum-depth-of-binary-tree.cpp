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
                    // bfs typically invovles a QUEUE
        
        // 1. BREADTH FIRST SEARCH APPROACH -- 
            // 1st establish a queue 
        queue<TreeNode*> nodeQueue; 

        // 2. have a base case 
        if(root != nullptr)
        {
            nodeQueue.push(root); 
        }

        // 3. declare var to return at end 
        int level = 0; 
        while(!nodeQueue.empty())
        {
            int size = nodeQueue.size(); 

            // iterate thr each node within each level of the tree
            for(int i = 0; i < size; i++)
            {
                // grab curr parent node
                TreeNode* node = nodeQueue.front(); 
                nodeQueue.pop(); 

                // push any children of that parent we just popped 
                if(node -> left != nullptr)
                {
                    nodeQueue.push(node -> left); 
                }
                if(node -> right != nullptr)
                {
                    nodeQueue.push(node -> right);
                }

                level++;
            }
        }

        return level;
    }
};