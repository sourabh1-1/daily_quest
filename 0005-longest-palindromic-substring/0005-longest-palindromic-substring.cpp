class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.length();
        vector<vector<int>> v (n,vector<int>(n,0));
        string ans="";
        int maxlength=0;
        for(int d=0;d<n;d++){
            for(int i=0,j=d+i;j<n;i++,j++){
                if(i==j)
                    v[i][j]=1;
                else if(d==1)
                    (s[i]==s[j])?v[i][j]=2:0;
                else{
                    if(s[i]==s[j] && v[i+1][j-1])
                        v[i][j]=v[i+1][j-1]+2;
                }
                if(v[i][j]){
                    if(j-i+1>maxlength){
                        maxlength=j-i+1;
                        ans=s.substr(i,maxlength);
                    }
                }
            }
        }
        return ans;
    }
};