class Solution {
public:
    vector<int>current;
    vector<vector<int>>allSubsets;
    void backtrack(int start,vector<int>nums){
        allSubsets.push_back(current);

        for(int i=start;i<nums.size();i++){
            current.push_back(nums[i]);
            backtrack(i+1,nums);
            current.pop_back();
        }

    }

    vector<vector<int>> subsets(vector<int>& nums) {
        backtrack(0,nums);
        return allSubsets;
        
    }
};