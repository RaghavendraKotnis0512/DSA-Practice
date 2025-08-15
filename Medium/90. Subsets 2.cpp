//sort the array just put them in a set to not get duplicates

class Solution {
public:
    vector<int>current;
    set<vector<int>>allSubsets;

    void backtrack(int start,vector<int>nums){
        allSubsets.insert(current);

        for(int i=start;i<nums.size();i++){
            current.push_back(nums[i]);
            backtrack(i+1,nums);
            current.pop_back();
        }

    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        backtrack(0,nums);
        vector<vector<int>>result(allSubsets.begin(),allSubsets.end());
        return result;

        
    }
};