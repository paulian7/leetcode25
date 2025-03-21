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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // preorder & inorder traversal - 
            // inorder - gurantees going through tree in order from l -> r
            // preorder - first val will be our root of our binary search tree 
                // then look at in-order to find this val 
                // can identify left and right subtree arrays
                    // the size of each one will tell us how to partition the preorder array
        
        // tech: recursive algorithm 

        // 1. deal with base case first bc using recrusion! 
            // if we don't have any nodes to traverse
        if(preorder.empty() || inorder.empty())
        {
            return nullptr;
        }

        // 2. ...otherwise create a treenode for our new bst 
            // first val will always be first val of the preorder array
        TreeNode *root = new TreeNode(preorder[0]);

        // 3. find the "first val" in preorder array in the INORDER ARRAY
            // subtracting the iterator by - inorder.begin() --> gives us the index val we need
        auto mid = find(inorder.begin(), inorder.end(), preorder[0]) - inorder.begin();

        // 4. create our left subtree now
            // starting at preorder.begin + 1 since we already dealt w/ the first element
                // aka we already added it as the root for our new bst
            // then takes it to whatever val mid is
        vector<int> leftPre(preorder.begin() + 1, preorder.begin() + mid + 1);

        // 5. creating right subtree
        vector<int> rightPre(preorder.begin() + mid + 1, preorder.end());

        vector<int> leftIn(inorder.begin(), inorder.begin() + mid);
        vector<int> rightIn(inorder.begin() + mid + 1, inorder.end());
        root->left = buildTree(leftPre, leftIn);
        root->right = buildTree(rightPre, rightIn);
        return root;
    }
};