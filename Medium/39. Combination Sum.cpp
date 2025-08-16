class Solution {
public:
    vector<int>curr;
    vector<vector<int>>result;

    void backtrack(int idx, vector<int>& candidates, int target){
        if(target==0){
            result.push_back(curr);
            return;
        }
        
        for(int i=idx;i<candidates.size();i++){
            if(candidates[i]<=target){
            curr.push_back(candidates[i]);
            backtrack(i,candidates,target-candidates[i]);
            curr.pop_back();
        }
    }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        backtrack(0,candidates,target);
        return result;
    }
};