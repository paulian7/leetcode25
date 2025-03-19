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
    vector<vector<int>> levelOrder(TreeNode* root) {
        // tech: breadth first search --> time comp: o(n)
            // need queue data structure for bfs
            // has first-in first-out
            // visiting every single node only once
        // space comp: o(n)

        // 1. declare 2d vector to return our result in 
        vector<vector<int>> travResult;

        // 2. cover edge cases 
        if(!root)
        {
            // when tree empty...
            return travResult;
        }

        // 3. declare and initialize queue for BFS traversal 
            // deque - added / removed from either front or back w/ this queue
        queue<TreeNode*> nodeQueue; 
        nodeQueue.push(root); // adding root element to queue 

        // 4. traverse thr tree til queue becomes empty 
        while(!nodeQueue.empty())
        {
            int qLength = nodeQueue.size(); 

            // 5. declare vector of integers to track each node in each level
            vector<int> treeLevel; 

            for(int i = nodeQueue.size(); i > 0; i--)
            { 
                TreeNode *currNode = nodeQueue.front(); 
                nodeQueue.pop(); // removes curr node

                // then need to add any children from that node we just popped
                if(currNode)
                {
                    // add that value we just popped off into its own array 
                    treeLevel.push_back(currNode -> val);

                    // now add its children to the queue
                    nodeQueue.push(currNode -> left);
                    nodeQueue.push(currNode -> right);
                }
            }

            if(!treeLevel.empty())
            {
                travResult.push_back(treeLevel);
            }
        }

        return travResult;
    }
};