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
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointSet ds(n);
        int components=0;
        int extra_connections=0;
        for(auto it: connections){
            int u=it[0];
            int v=it[1];
            if(ds.find_par(u)==ds.find_par(v))
                extra_connections++;
            else
                ds.unionByRank(u, v);
        }
        for(int i=0;i<n;i++){
            if(ds.parent[i]==i)
                components++;
        }
        if(components-1<=extra_connections)
            return components-1;
        return -1;
    }
};