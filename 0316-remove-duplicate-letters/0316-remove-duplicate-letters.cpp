class Solution {
public:
    string removeDuplicateLetters(string s) {
        string t="";
        vector<int> f(26,0),v(26,0);
        for(auto x: s) 
            f[x-'a']++;
        for(int i=0;i<s.size();i++){
            f[s[i]-'a']--;
            if(v[s[i]-'a']!=0) 
                continue;
            while(!t.empty() && t.back()>s[i] && f[t.back()-'a']>0){
                v[t.back()-'a']=0;
                t.pop_back();
            }
            v[s[i]-'a']=1;
            t.push_back(s[i]);
        }
        return t;
    }
};