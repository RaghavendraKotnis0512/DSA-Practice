class Solution {
public:
    bool isValid(string s) {
        //This is using stack
        //Time complexity O(n) when we traverse through string push and pop requires O(1)
        //Space complexity O(n) since stack is being used
        stack<char>st;
        int i=0;

        while(i<s.length()){
            if(st.empty()){
                st.push(s[i]);
            }
          else if((st.top()=='(' && s[i]==')')||(st.top()=='[' && s[i]==']')||(st.top()=='{' && s[i]=='}')){
                st.pop();
            }else{
                st.push(s[i]);
            }
            i++;
        }
        return st.empty();
    }
};