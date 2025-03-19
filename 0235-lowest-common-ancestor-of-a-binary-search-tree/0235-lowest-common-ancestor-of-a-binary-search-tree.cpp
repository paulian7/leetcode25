/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // time complexity: o(logn)
            // will only have to visit 1 node for every single level in the tree
        TreeNode *currNode = root; 

        while(currNode != nullptr)
        {
             if(p -> val > currNode -> val && q -> val > currNode -> val)
             {
                // going down to right subtree
                currNode = currNode -> right;
             }
             else if(p -> val < currNode -> val && q -> val < currNode -> val)
             {
                // going down to left subtree 
                currNode = currNode -> left; 
             }
             else 
             {
                return currNode; 
             }
        }

        return nullptr;
    }
};