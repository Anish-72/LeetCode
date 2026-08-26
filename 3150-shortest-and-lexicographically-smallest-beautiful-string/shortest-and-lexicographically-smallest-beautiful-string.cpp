class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        vector<int> ones;

        for(int i = 0; i<s.length(); i++){
            if(s[i] == '1'){
                ones.push_back(i);
            }
        }
        if(ones.size() < k){
            return "";
        }
        string ans = "";
        for(int i = 0; i + k - 1 < ones.size(); i++){
            int si = ones[i];
            int ei = ones[i+k-1];
            

            string curr = s.substr(si, ei-si+1);

            if(ans=="" || curr.size() < ans.size() || (ans.size() == curr.size() && curr < ans)){
                ans = curr;
            }

        
        }
         return ans;
    }
};