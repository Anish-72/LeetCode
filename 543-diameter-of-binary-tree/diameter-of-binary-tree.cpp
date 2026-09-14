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
private:
    int helper(TreeNode* root, int &maxHeight){
        if(root == nullptr){
            return 0;
        }

        int leftHeight = helper(root->left, maxHeight);
        int rightHeight = helper(root->right, maxHeight);
        maxHeight = max(maxHeight, leftHeight + rightHeight);

        return 1 + max(leftHeight, rightHeight);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int maxHeight = 0;

        helper(root, maxHeight);

        return maxHeight;
    }
};