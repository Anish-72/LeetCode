class Solution {
public:
    string tofreq(string str) {

        vector<int> freq(26, 0);

        for (int i = 0; i < str.length(); i++) {
            freq[str[i] - 'a']++;
        }

        string ans = "";

        for (int i = 0; i < 26; i++) {
            ans += (char)(i + 'a');
            ans += freq[i];
        }
        return ans;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        if (strs.empty()) {
            return vector<vector<string>>();
        }

        unordered_map<string, vector<string>> udm;
        vector<vector<string>> ans;

        for (string str : strs) {
            string freq = tofreq(str);

            if (udm.count(freq)) {

                udm[freq].push_back(str);

            } else {
                vector<string> newstr;
                newstr.push_back(str);
                udm[freq] = newstr;
            }
        }
        for( auto& pair : udm){
            ans.push_back(pair.second);
        }
        return ans;
    }
};