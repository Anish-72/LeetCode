class Solution {
        void helper(vector<int>& candidates, int target, vector<vector<int>>& result,
            vector<int>& curr, int idx){

                if(target == 0){
                    result.push_back(curr);
                }
                if(target < 0){
                    return;
                }

                for(int i = idx; i<candidates.size(); i++){
                    curr.push_back(candidates[i]);

                    helper(candidates, target - candidates[i], result, curr, i);
                    curr.pop_back();
                }
            } 
public :
        vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

            vector<vector<int>> result;
            vector<int> curr;
            helper(candidates, target,result,curr,0);

            return result;
    }
};