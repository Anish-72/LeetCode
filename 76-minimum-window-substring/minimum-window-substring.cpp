class Solution {
public:
    string minWindow(string s, string t) {

        vector<int> udm (256,0);

        for(char c : t){
            udm[c]++;
        }
        int count = 0;
        int sidx = 0;
        int minlength = INT_MAX;

        int l = 0, r = 0;

        while(r < s.length()){
            if(udm[s[r]]>0) count++;
            udm[s[r]]--;

            while(count == t.size()){
                if(r-l+1 < minlength){
                    sidx = l;
                    minlength = r - l + 1;
                }
                udm[s[l]]++;
                if(udm[s[l]]>0) count--;
                l++;
            }
            r++;
        }
        return (minlength == INT_MAX) ? "" : s.substr(sidx,minlength);

    }
};