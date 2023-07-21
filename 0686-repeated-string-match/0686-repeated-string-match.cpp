class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        int ans=0;
        string s=a;
        int n=b.length()/a.length();
        for(int i=0;i<=n+1;i++){
            if(s.find(b)!=string::npos)
                return ans+1;
            s+=a;
            ans++;
        }
        return -1;
    }
};