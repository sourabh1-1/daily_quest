class Solution {
    int i=0;
public:
    string fun(string &s){
        string ans="";
        while(i<s.size()){
            if(s[i]=='('){
                i++;
                ans+=fun(s);
            }
            else if(s[i]==')'){
                reverse(ans.begin(), ans.end());
                i++;
                return ans;
            }
            else{
                ans+=s[i];
                i++;
            }
        }
        return ans;
    }
    string reverseParentheses(string s) {
        return fun(s);
        // string rev="";
        // stack<char> st;
        // for(int i=0;i<s.size();i++){
        //     if(s[i]!=')')
        //         st.push(s[i]);
        //     else{
        //         char c=st.top();
        //         string temp="";
        //         for(c;c!='(';c=st.top()){
        //             temp+=c;
        //             st.pop();
        //         }
        //         st.pop();
        //         for(int j=0;j<temp.size();j++){
        //             st.push(temp[j]);
        //         }
        //         rev=temp;
        //     }
        // }
        // return rev;
    }
};