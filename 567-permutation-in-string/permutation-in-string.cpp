class Solution {
public:
    bool isfreq(vector<int>& freq, vector<int>& windfreq) {
        for (int i = 0; i < 26; i++) {
            if (freq[i] != windfreq[i]) {
                return false;
            }
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {

        vector<int> freq(26, 0);

        for (char c : s1) {
            freq[c - 'a']++;
        }
        int windsize = s1.length();
        vector<int> windfreq(26, 0);
        for (int i = 0; i < s2.length(); i++) {
            windfreq.assign(26, 0);
            int windidx = 0;
            int idx = i;
            while (windidx < windsize && idx < s2.length()) {
                windfreq[s2[idx] - 'a']++;
                windidx++;
                idx++;
            }
            if (isfreq(freq, windfreq)) {
                return true;
            }
        }
        return false;
    }
};