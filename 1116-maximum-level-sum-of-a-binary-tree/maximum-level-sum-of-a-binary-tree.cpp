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
public:
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> que;
        que.push(root);
        int currLevel = 0;
        int maxSum = INT_MIN;
        int ans = 0;

        while (!que.empty()) {
            int size = que.size();
            currLevel++;
            int sum = 0;
            for (int i = 0; i < size; i++) {
                TreeNode* curr = que.front();
                que.pop();
                sum += curr->val;

                if (curr->left) {
                    que.push(curr->left);
                }
                if (curr->right) {
                    que.push(curr->right);
                }
            }
            if(sum>maxSum){
                ans = currLevel;
                maxSum = sum;
            }
        }
        return ans;
    }
};