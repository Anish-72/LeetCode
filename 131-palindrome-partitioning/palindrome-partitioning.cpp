class Solution {
private:
    bool isPalindrome(string part) {
        int left = 0;
        int right = part.size()-1;
        while (left < right) {
            if (part[left] != part[right]) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
    void helper(string s,vector<vector<string>> &result, vector<string> &ans){
        if(!s.size()){
            result.push_back(ans);
            return;
        }
        for(int i = 0; i<s.size(); i++){
            string part = s.substr(0, i+1);

            if(isPalindrome(part)){
                ans.push_back(part);
                helper(s.substr(i+1),result, ans);
                ans.pop_back();
            }
        }
        return;
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;

        vector<string> part;

        helper(s, result, part);

        return result;
    }
};