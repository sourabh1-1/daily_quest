class Solution {
public:
    int numberOfSubstrings(string s) {
        int i=0;
        int n=s.size();
        int count=0;
        vector<int> index(3, -1);
        while(i<n){
            index[s[i]-'a']=i;
            if(index[0]!=-1 && index[1]!=-1 && index[2]!=-1){
                int mini=min(index[0], min(index[1], index[2]));
                count=count+mini+1;
            }
            i++;
        }
        return count;
    }
};