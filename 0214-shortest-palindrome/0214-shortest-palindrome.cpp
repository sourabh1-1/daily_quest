class Solution {
    int fun(const string &s, const string &t) {
        string newString=t+'#'+s;
        vector<int> pi(newString.length(), 0);
        int i=1, k=0;
        while(i<newString.length()) {
            if(newString[i]==newString[k]){
                k++;
                pi[i]=k;
                i++;
            } 
            else{
                if(k>0)
                    k=pi[k-1];
                else{
                    pi[i]=0;
                    i++;
                }
            }
        }
        return pi.back();
    }
public:
    string shortestPalindrome(string s) {
        int count=fun(string(s.rbegin(), s.rend()), s);
        return string(s.rbegin(), s.rend()).substr(0, s.length()-count)+s;
    }
};