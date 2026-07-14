class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> udm;
        int maxCount = 0;
        int left = 0; // Left pointer for our sliding window

        for(int right = 0; right < s.length(); right++) {
            char ch = s[right];
            
            // If we have seen the character and it is inside our current window
            if(udm.count(ch) && udm[ch] >= left) {
                // Shrink the window by moving the left pointer 
                // just past the previous occurrence of this character
                left = udm[ch] + 1;
            }
            
            // Update the latest index of the character
            udm[ch] = right;
            
            // Calculate max length for the current window
            maxCount = max(maxCount, right - left + 1);
        }
        
        return maxCount;
    }

};