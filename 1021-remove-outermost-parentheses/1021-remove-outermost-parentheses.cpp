class Solution {
public:
    string removeOuterParentheses(string s) {
        int count=0;
        string ans;
        for(auto c:s){
            if(count==0 && c=='(')
                count--;
            else if(count==-1 && c==')')
                count++;
            else{
                ans.push_back(c);
                if(c=='(')
                    count--;
                else
                    count++;
            }
        }
        return ans;
    }
};