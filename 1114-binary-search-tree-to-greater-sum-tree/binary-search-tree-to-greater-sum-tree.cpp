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
int Sum = 0;
    int helper(TreeNode* root){
        if(root == nullptr){
           return 0;    
        }
        helper(root->right);
        root->val += Sum;
        Sum = root->val;
        helper(root->left);

        return root->val;

    }
public:
    TreeNode* bstToGst(TreeNode* root) {
        
        helper(root);
        return root;
    }
};