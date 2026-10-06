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
    int widthOfBinaryTree(TreeNode* root) {
        if(root == nullptr){
            return 0;
        }

        queue<pair<TreeNode*, long long>> q;
        int ans = 0;
        int maxAns = INT_MIN;
        q.push({root, 0});
        

        while (!q.empty()) {
            int size = q.size();
            long long firstIdx = -1;
            long long lastIdx = -1;

            long long minIdx = q.front().second;

            for (int i = 0; i < size; i++) {

                if(i == 0) firstIdx = q.front().second;
                if(i == size - 1) lastIdx = q.front().second;

                TreeNode* curr = q.front().first;
                long long idx = q.front().second - minIdx;
                
                q.pop();

                if (curr->left) q.push({curr->left, (idx * 2) + 1});
                if (curr->right) q.push({curr->right, (idx * 2) + 2});
            }
           
            maxAns = max(maxAns,(int)(lastIdx - firstIdx + 1));
        }
        return maxAns;
    }
};