class Solution {
public:

//This is by sorting method
    bool isAnagram(string s, string t) {
        int i=0;
        int j=0;
        if(s.length()!=t.length()){
            return false;
        }
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        while(i<s.length()){
            if(s[i]==t[i]){
                i++;
                continue;
            }else{
                return false;
            }
        }
        return true;
    }
};




//making the value 0 doesnt remove the key from the map
class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int>mpp;
        if(s.length()!=t.length()){
            return false;
        }

        for(char it:s){
            mpp[it]++;
        }
        for(int i=0;i<t.length();i++){
            if(mpp.find(t[i])!=mpp.end()){
                mpp[t[i]]--;
                if (mpp[t[i]] == 0) {
                    mpp.erase(t[i]); // ✅ Remove key if count becomes 0
                }
            }else{
                return false;
            }
        }
        if(mpp.size()==0){
            return true;
        }
        return false;
    }
};