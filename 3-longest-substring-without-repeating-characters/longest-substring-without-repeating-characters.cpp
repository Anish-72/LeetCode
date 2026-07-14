class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<int,int> udm;
        int left = 0;
        int maxCount = 0;

        for(int right = 0; right<s.length(); right++){
            char ch = s[right];
            
            if(udm.count(ch) && udm[ch]>=left) {

                left = udm[ch] + 1;
            }

            udm[ch] = right;
            maxCount = max(maxCount, right - left + 1);
        }
        return maxCount;
    }
};