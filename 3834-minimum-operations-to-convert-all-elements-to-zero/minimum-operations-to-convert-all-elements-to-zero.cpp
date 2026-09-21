class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ops = 0;
        vector<int> st;
        
        for (int num : nums) {
            while (!st.empty() && st.back() > num) {
                st.pop_back();
                ops++;
            }
            if (num == 0 || (!st.empty() && st.back() == num)) {
                continue;
            }
            st.push_back(num);
        }
        
        ops += st.size();
        return ops;
    }
};