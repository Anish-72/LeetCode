class Solution {
public:
    void reverseString(vector<char>& s) {
        int si = 0;
        int ei = s.size()-1;

        while(si<ei){
            swap(s[si],s[ei]);

            si++;
            ei--;
        }
    }
};