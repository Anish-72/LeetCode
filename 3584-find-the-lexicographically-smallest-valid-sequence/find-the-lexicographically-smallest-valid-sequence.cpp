class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int m = word1.length();
        int n = word2.length();
        vector<int> last(n, -1);
        
        // Step 1: Right-to-left exact match
        int i = m - 1;
        int j = n - 1;
        while (i >= 0 && j >= 0) {
            if (word1[i] == word2[j]) {
                last[j] = i;
                j--;
            }
            i--;
        }
        
        vector<int> ans;
        bool canSkip = true;
        j = 0;
        
        // Step 2: Left-to-right greedy match
        for (i = 0; i < m; ++i) {
            if (j == n) break;
            
            if (word1[i] == word2[j]) {
                ans.push_back(i);
                j++;
            } else if (canSkip && (j == n - 1 || i < last[j + 1])) {
                canSkip = false;
                ans.push_back(i);
                j++;
            }
        }
        
        return j == n ? ans : vector<int>();
    }
};