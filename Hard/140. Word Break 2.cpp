// void backtrack(parameters) {
//     if (solution_found)  // here: any path is a subset
//         store solution

//     for (each choice in choices) {
//         make_choice      // push element into 'current'
//         backtrack        // go deeper with next index
//         undo_choice      // pop element from 'current'
//     }
// }


class Solution {
public:

    vector<string>result;
    string ans="";
    void backtrack(string s, vector<string>& wordDict){
        if(s.length()==0){
            result.push_back(ans.substr(0, ans.size() - 1));
        }
        for(int i=0;i<wordDict.size();i++){
            if(s.rfind(wordDict[i],0)==0){
                int oldLen=ans.size();
                ans+=wordDict[i]+" ";
            s.erase(0,wordDict[i].size());
            backtrack(s,wordDict);
            s.insert(0,wordDict[i]);
            ans.resize(oldLen);//to remove the last word and try other options
            }
           
        }
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        backtrack(s,wordDict);
        return result;
    }
};