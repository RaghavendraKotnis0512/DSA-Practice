// start=mpp[curr]+1; this is done because we have to remove all the characters until the repeating character is found
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>mpp;
        int maxLength=0;
        int start=0;
        for(int end=0;end<s.length();end++){
            char curr=s[end]; //storing each character to find in the map

            if(mpp.find(curr)!=mpp.end() && mpp[curr]>=start){
                start=mpp[curr]+1;  //this is done because we have to remove all the characters until the repeating character is found dry run abcdb and check
            }

            mpp[curr]=end; //to update the latest index found in map
            maxLength=max(maxLength,end-start+1);
        }
        return maxLength;
        
    }
};