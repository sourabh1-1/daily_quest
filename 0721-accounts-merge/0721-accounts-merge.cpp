class DisjointSet{
public:
    vector<int> parent, rank;
    DisjointSet(int n){
        parent.resize(n);
        rank.resize(n, 0);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
    }
    int find_par(int node){
        if(node==parent[node])
            return node;
        return parent[node]=find_par(parent[node]);
    }
    void unionByRank(int node1, int node2){
        int ulp_node1=find_par(node1);
        int ulp_node2=find_par(node2);
        if(ulp_node1==ulp_node2)
            return;
        if(rank[ulp_node1]<rank[ulp_node2])
            parent[ulp_node1]=ulp_node2;
        else if(rank[ulp_node2]<rank[ulp_node1])
            parent[ulp_node2]=ulp_node1;
        else{
            parent[ulp_node2]=ulp_node1;
            rank[ulp_node1]++;
        }
    }
};
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        DisjointSet ds(n);
        unordered_map<string, int> mailNode;
        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
                string mail=accounts[i][j];
                if(mailNode.find(mail)==mailNode.end())
                    mailNode[mail]=i;
                else{
                    ds.unionByRank(i, mailNode[mail]);
                }
            }
        }
        vector<string> mergeMail[n];
        for(auto it: mailNode){
            string mail=it.first;
            int node=ds.find_par(it.second);
            mergeMail[node].push_back(mail);
        }
        vector<vector<string>> ans;
        for(int i=0;i<n;i++){
            if(mergeMail[i].size()==0)
                continue;
            sort(mergeMail[i].begin(), mergeMail[i].end());
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            for(auto it: mergeMail[i]){
                temp.push_back(it);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};