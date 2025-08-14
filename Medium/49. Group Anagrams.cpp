class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mpp;
        for(int i=0;i<strs.size();i++){
            string sorted=strs[i];
            sort(sorted.begin(),sorted.end());
        
                mpp[sorted].push_back(strs[i]);

        }
        vector<vector<string>>result;
        for(auto it:mpp){
            result.push_back(it.second);
        }
        return result;
    }
};