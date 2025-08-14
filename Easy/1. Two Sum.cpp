class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //Hash map- Optimal approach
        //this is one pass approach, for two pass approah at first we will have to enter the elements in the map along with their index so it will take 2 for loops 
        unordered_map<int,int>mpp;

        for(int i=0;i<nums.size();i++){
            int ans=target-nums[i];
            if(mpp.find(ans)!=mpp.end()){
                return {mpp[ans],i};
            }

            mpp[nums[i]]=i;
        }
return {};
        
    }
};