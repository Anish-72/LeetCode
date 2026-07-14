class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
       sort(intervals.begin(), intervals.end());

       vector<vector<int>>result;
       result.push_back(intervals[0]);
       

       for(int i = 1; i<intervals.size(); i++){
           int pre_ei = result.back()[1];
           int curr_si = intervals[i][0];
           int curr_ei = intervals[i][1];

           if(curr_si <= pre_ei){
            result.back()[1] = max(pre_ei, curr_ei);
           }else{
             result.push_back(intervals[i]);
           }
       }
       return result;
    }
};