class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<string, int> prefix;
        for(int num: arr1){
            string snum=to_string(num);
            string pre="";
            for(char ch: snum){
                pre+=ch;
                prefix[pre]++;
            }
        }
        int maxi=0;
        for(int num: arr2){
            string snum=to_string(num);
            string pre="";
            for(char ch: snum){
                pre+=ch;
                if(prefix.find(pre)!=prefix.end())
                    maxi=max(maxi, static_cast<int>(pre.length()));
            }
        }
        return maxi;
    }
};