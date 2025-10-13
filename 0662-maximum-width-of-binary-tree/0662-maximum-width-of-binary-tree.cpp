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
    int widthOfBinaryTree(TreeNode* root) {
        // tech: breadth first search -- most intuitive here! 
            // can allow us to get the width of each tree level
        
        // time & space comp: 
            // time: o(n) -- size of tree 
            // space: o(n)
        
        // 1. declare and initialize result for now 
        int result = 0; 

        // 2. declare OUR QUEUE (bc doing BFS)
            // each element in queue will hold 3 vals 
                // [node itself, what number pos it is, level]
        queue<tuple<TreeNode*, uint, int>> nodeQueue; 

        // 3. add first element to queue 
        nodeQueue.push({root, 1, 0});

        // 4. set some helper variables
        int prevLevel = 0; 
        int prevNum = 1; 

        // 5. start iterating thr tree (once queue empty --> no nodes left to iterate thr)
        while(!nodeQueue.empty())
        {
            // take the 3 tuple vals curr residing in first node in queue...
                // and add them respectively into -- node, num, level
            auto [node, num, level] = nodeQueue.front();

            // now pop it from queue --> need to deal w/ its children now
            nodeQueue.pop(); 

            // update "level" if we've went to another level 
            if(level > prevLevel)
            {
                // update prevLevel to the currently highest level
                prevLevel = level; 
                // set to first node in the level (leftmost)
                prevNum = num;
            }

            // calc width 
                // takes rightMost node in level - leftMost node in level + 1 = corr width! 
                    // + 1 is the offset we're including to make it corr
            result = max(result, int(num - prevNum) + 1);

            // RMBR -- to deal w/ the children
            if(node -> left) // left child
            {
                // num * 2 -- (for left childs only)
                    // gets the corr number of nodes (if we're doing it from left -> right)
                nodeQueue.push({node -> left, num * 2, level + 1});
            }
            if(node -> right) // right child 
            {
                // num * 2 + 1 -- (for right childs only)
                    // gets the corr num of nodes (if we're doing it from left -> right)
                nodeQueue.push({node -> right, num * 2 + 1, level + 1});

            }
        }

        return result;
    }
};