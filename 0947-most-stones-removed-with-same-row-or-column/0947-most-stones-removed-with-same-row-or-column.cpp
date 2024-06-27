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
    int removeStones(vector<vector<int>>& stones) {
        int maxRow=0;
        int maxCol=0;
        for(auto it: stones){
            maxRow=max(maxRow, it[0]);
            maxCol=max(maxCol, it[1]);
        }
        DisjointSet ds(maxRow+maxCol+2);
        unordered_map<int, int> stoneNode;
        for(auto it: stones){
            int nodeRow=it[0];
            int nodeCol=it[1]+maxRow+1;
            stoneNode[nodeRow]=1;
            stoneNode[nodeCol]=1;
            ds.unionByRank(nodeRow, nodeCol);
        }
        int count=0;
        for(auto it: stoneNode){
            if(ds.find_par(it.first)==it.first)
                count++;
        }
        return stones.size()-count;
    }
};