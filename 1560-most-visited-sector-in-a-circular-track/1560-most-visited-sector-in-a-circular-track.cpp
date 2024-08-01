class Solution {
public:
    vector<int> mostVisited(int n, vector<int>& rounds) {
        vector<int> hash(n, 0);
        int m=rounds.size();
        for(int i=0;i<m-1;i++){
            int s=rounds[i];
            int e=rounds[i+1];
            while(s!=e){
                hash[s-1]++;
                s=s%n+1;
            }
        }
        hash[rounds[m-1]-1]++;
        int maxi=*max_element(hash.begin(), hash.end());
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(hash[i]==maxi)
                ans.push_back(i+1);
        }
        return ans;
    }
};