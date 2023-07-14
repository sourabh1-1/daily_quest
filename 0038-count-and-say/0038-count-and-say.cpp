class Solution {
public:
    string countAndSay(int n) {
        if(n==1)
            return "1";
        string s=countAndSay(n-1);
        int count=1;
        string ans="";
        for(int i=0;i<s.size();i++){
            if(i<s.size() && s[i]==s[i+1]){
                count++;
            }else{
                ans+=char(count+int('0'));
                ans+=s[i]; 
                count=1;
            }
        }
        return ans;
    }
};