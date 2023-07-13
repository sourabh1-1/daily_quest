class Solution {
public:
    string reverseWords(string s) {
        string ans;
        string t="";
        int n=s.length();
        int x=0;
        while(s[n-1]==' ')
            n--;
        while(s[x]==' ')
            x++;
        for(int i=n-1;i>=x;i--){
            if(s[i]==' '){
                if(!t.empty()){
                    reverse(t.begin(),t.end());
                    ans+=t;
                    ans+=' ';
                    t="";
                }
            }
            else{
                t+=s[i];
            }
        }
        reverse(t.begin(),t.end());
        ans+=t;
        return ans;
    }
};