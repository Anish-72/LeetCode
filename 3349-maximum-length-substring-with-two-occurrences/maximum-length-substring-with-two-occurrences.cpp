class Solution {
public:
    int maximumLengthSubstring(string s) {
        unordered_map<char,int> map;
        int left = 0;
        int right = 0;
        int count = 0;
        int maxCount = INT_MIN;

        while(right < s.length()){
            if(!map[s[right]]){
                map[s[right]] = 1;
                count++;
                maxCount = max(maxCount, count);
            }else{
                map[s[right]]++;
                count++;
                while(map[s[right]] > 2){
                    map[s[left]]--;
                    left++;
                    count--;
                }
                maxCount = max(maxCount, count);
            }
            right++;
        }
        return maxCount;

    }
};