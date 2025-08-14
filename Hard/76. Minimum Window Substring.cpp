class Solution {
public:
    string minWindow(string s, string t) {

        if(t.size()>s.size()){
            return "";
        }

        unordered_map<char, int>mpp;

        for(auto it:t){
            mpp[it]++;
        }
        int matchedCount=0;
        int requiredUnique=mpp.size();
        int min_len=INT_MAX;
        int startIdx=0;
        int l=0;

        for(int r=0;r<s.size();r++){
            if(mpp.find(s[r])!=mpp.end()){
                mpp[s[r]]--;
                if(mpp[s[r]]==0) matchedCount++;
            }
        
        while(matchedCount==requiredUnique){
            if(r-l+1<min_len){
                min_len=r-l+1;
                startIdx=l;
            }
            if(mpp.find(s[l])!=mpp.end()){
                if(mpp[s[l]]==0){
                    matchedCount--;
                }
                mpp[s[l]]++;
            }
            l++;
        }

        }
        return (min_len==INT_MAX)?"":s.substr(startIdx,min_len);
    }
};