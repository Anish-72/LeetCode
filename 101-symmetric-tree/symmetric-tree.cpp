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
    void helper(TreeNode* real, TreeNode* img, bool& ans){
        if(real== nullptr && img == nullptr){//BC
            return;
        }else if(real== nullptr || img == nullptr){
            ans = false;
            return;
        }
        if(real->val != img->val){
            ans = false;
            return;
        }
        helper(real->right, img->left,ans);
        helper(real->left, img->right,ans);
        return;
    }
public:
    bool isSymmetric(TreeNode* root) {
        TreeNode* real = root->left;
        TreeNode* img = root->right;
        bool ans = true;
        helper(real,img, ans);
        return ans;
    }
};