class Solution {
public:
    void helperFn(vector<int>& candidates, int target,
                  vector<vector<int>>& result, vector<int>& arr, int idx) {

        if (target == 0) {
            result.push_back(arr);
            return;
        }

        if (target < 0) {
            return;
        }

        for (int i = idx; i < candidates.size(); i++) {

            if(i>idx && candidates[i] == candidates[i-1]){
                continue;
            }

            if(candidates[i] > target){
                break;
            }

            arr.push_back(candidates[i]);

            helperFn(candidates, target - candidates[i], result, arr, i+1);

            arr.pop_back();
        }
        return;
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> arr;

        sort(candidates.begin(), candidates.end());
        helperFn(candidates, target, result, arr, 0);
        
        return result;
    }
};