class Solution {
public:
    int firstUniqChar(string s) {
        vector<int>freq(26,0);//key val
        
        for(int i = 0; i<s.length(); i++){
            freq[s[i] - 97]++;
        }

        for(int i = 0; i<s.length(); i++){
            if(freq[s[i] - 97] == 1){
                return i;
            }
        }
        return -1;
    }
};