/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
private:
    int helperSum(TreeNode* root, int& maxSum) {
        if (root == nullptr) {
            return 0;
        }

        int leftSum = max(0,helperSum(root->left, maxSum));
        int rightSum = max(0,helperSum(root->right, maxSum));

        int sum = root->val + rightSum + leftSum;

        maxSum = max(maxSum, sum);

        
        return root->val + max(leftSum, rightSum);
    }

public:
    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;

        helperSum(root, maxSum);

        return maxSum;
    }
};