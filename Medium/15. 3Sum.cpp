//Brute Force
//Inserted it into a set because there should be no duplicates remember result is added into set and not nums
//without sorting first, the same logical triplet could be inserted in different orders, and the set would treat them as different triplets.
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
       
       set<vector<int>>s;
        sort(nums.begin(),nums.end());
       for(int i=0;i<nums.size();i++){
        for(int j=i+1;j<nums.size();j++){
            for(int k=j+1;k<nums.size();k++){
                if(nums[i]+nums[j]+nums[k]==0 && (i != j && i != k && j != k)){
                    s.insert({nums[i],nums[j],nums[k]});
                }
            }
        }
       }
       vector<vector<int>>result(s.begin(),s.end());
        return result;
        
    }
};


//Optimal approach without using set

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>result;
        sort(nums.begin(),nums.end());
        
        for(int i=0;i<nums.size();i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            int j=i+1;
            int k=nums.size()-1;

            while(j<k){
                if(nums[i]+nums[j]+nums[k]==0){
                    result.push_back({nums[i],nums[j],nums[k]});
                    j++;
                    k--;
                while (j < k && nums[j] == nums[j - 1]) j++; //can use if as well
                while (j < k && nums[k] == nums[k + 1]) k--;
                }
                else if (nums[i]+nums[j]+nums[k] < 0) {
                    j++;
                }
                else {
                    k--;
                }
            }
            }
        return result;
    }
};