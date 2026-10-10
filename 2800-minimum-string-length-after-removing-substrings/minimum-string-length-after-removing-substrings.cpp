class Solution {
public:
    int minLength(string s) {

        string partA = "AB", partB = "CD";
        int partLen = 2;

        string res = "";

        for (char c : s) {
            res.push_back(c);

            if (res.length() >= partLen) {
                if (res.substr(res.length() - partLen) == partA ||
                    res.substr(res.length() - partLen) == partB) {

                    res.erase(res.length() - partLen);
                }
            }
        }

        return res.length();
    }
};