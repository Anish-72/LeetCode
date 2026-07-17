class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()){
            return false;
        }
        unordered_map<char,int> udm;

        for(char ch : s){
            udm[ch]++;
        }
        for(char ch : t){
           udm[ch]--;
        }
        for(auto const[key, value] : udm){
            if(value != 0){
                return false;
            }
        }
        return true;

    }
};