class Solution {
public:
    int minimizedStringLength(string s) {
        sort(s.begin(),s.end());
        int count=1;
        for(int i=1;i<s.length();i++){
            if(s[i]!=s[i-1])
                count++;
        }
        return count;
    }
};