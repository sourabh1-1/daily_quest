class Solution {
public:
    int countSegments(string s) {
        int count=0;
        for(int i=0;i<s.length();i++){
            if(s[i]!=' '){
                while(s[i]!=' ' && i<s.length())
                    i++;
                count++;
            }
        }
        return count;
    }
};