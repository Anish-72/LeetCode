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
    vector<int> helper(TreeNode* root, vector<int>&stack){
        if(root == nullptr){
            return {};
        }
        helper(root->left, stack);
        helper(root->right, stack);

        stack.push_back(root->val);

        return stack;
    }
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>stack;
        return helper(root, stack);
    }
};