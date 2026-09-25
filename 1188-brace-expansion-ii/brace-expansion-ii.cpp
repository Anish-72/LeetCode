class Solution {
public:
    vector<string> braceExpansionII(string expression) {
        queue<string> q;
        unordered_set<string> seen;
        set<string> res;
        
        q.push(expression);
        seen.insert(expression);
        
        while (!q.empty()) {
            string s = q.front();
            q.pop();
            
            int right = s.find('}');
            if (right == string::npos) {
                res.insert(s);
                continue;
            }
            
            int left = s.rfind('{', right);
            
            string before = s.substr(0, left);
            string after = s.substr(right + 1);
            string middle = s.substr(left + 1, right - left - 1);
            
            stringstream ss(middle);
            string piece;
            while (getline(ss, piece, ',')) {
                string next = before + piece + after;
                if (seen.find(next) == seen.end()) {
                    seen.insert(next);
                    q.push(next);
                }
            }
        }
        
        return vector<string>(res.begin(), res.end());
    
    }
};