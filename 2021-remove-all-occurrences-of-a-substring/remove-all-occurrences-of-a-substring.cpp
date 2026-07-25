class Solution {
public:
    string removeOccurrences(string s, string part) {
        string ans = "";
        int partLen = part.length();

        for (char c : s) {
            ans.push_back(c); 

            if (ans.length() >= partLen) {
                
                if (ans.substr(ans.length() - partLen) == part) {
                   
                    ans.erase(ans.length() - partLen); 
                }
            }
        }
        
        return ans;
    }
};