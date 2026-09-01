class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> stk;
        unordered_map<int,int> udm;
        int n = nums2.size() - 1;
        vector<int> temp(n+1, -1);
        stk.push(nums2[n]);
        temp[n] = -1;
        udm[nums2[n]] = n;
        for(int i = n-1; i>=0; i--){
            udm[nums2[i]] = i;
            while(!stk.empty() && nums2[i] > stk.top()){
                stk.pop();
            }
            if(stk.empty()){
                temp[i] = -1;
            }else{
                temp[i] = stk.top();
            }

            stk.push(nums2[i]);
        }
        vector<int> ans(nums1.size(),-1);
        for(int i = 0; i<nums1.size(); i++){
            ans[i] = temp[udm[nums1[i]]];
        }
        return ans;
    }
};