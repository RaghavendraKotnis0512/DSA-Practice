class Solution {
public:

    vector<int>curr;
    vector<vector<int>>result;
    vector<bool>used;
    void backtrack(vector<int>& nums){
        if(curr.size()==nums.size()){
            result.push_back(curr);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(used[i]) continue;
            curr.push_back(nums[i]);
            used[i]=true;
            backtrack(nums);
            used[i]=false;
            curr.pop_back();
            
        }

    }

    vector<vector<int>> permute(vector<int>& nums) {
        used.assign(nums.size(),false);
        backtrack(nums);
        return result;
        
    }
};