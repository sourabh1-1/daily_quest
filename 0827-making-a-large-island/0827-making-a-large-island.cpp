class DisjointSet{
public:
    vector<int> parent, rank, size;
    DisjointSet(int n){
        parent.resize(n);
        rank.resize(n, 0);
        size.resize(n);
        for(int i=0;i<n;i++){
            parent[i]=i;
            size[i]=1;
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
    void unionBySize(int node1, int node2){
        int ulp_node1=find_par(node1);
        int ulp_node2=find_par(node2);
        if(ulp_node1==ulp_node2)
            return;
        if(size[ulp_node1]<size[ulp_node2]){
            parent[ulp_node1]=ulp_node2;
            size[ulp_node2]+=size[ulp_node1];
        }
        else{
            parent[ulp_node2]=ulp_node1;
            size[ulp_node1]+=size[ulp_node2];
        }
    }
};
class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        DisjointSet ds(n*n);
        for(int row=0;row<n;row++){
            for(int col=0;col<n;col++){
                if(grid[row][col]==0)
                    continue;
                int nodeNo=row*n+col;
                int dr[]={-1, 0, 1, 0};
                int dc[]={0, 1, 0, -1};
                for(int i=0;i<4;i++){
                    int newRow=row+dr[i];
                    int newCol=col+dc[i];
                    if(newRow>=0 && newRow<n && newCol>=0 && newCol<n && grid[newRow][newCol]==1){
                        int adjNodeNo=newRow*n+newCol;
                        ds.unionBySize(nodeNo, adjNodeNo);
                    }
                }
            }
        }
        int maxi=0;
        for(int row=0;row<n;row++){
            for(int col=0;col<n;col++){
                if(grid[row][col]==1)
                    continue;
                int nodeNo=row*n+col;
                set<int> components;
                int dr[]={-1, 0, 1, 0};
                int dc[]={0, 1, 0, -1};
                for(int i=0;i<4;i++){
                    int newRow=row+dr[i];
                    int newCol=col+dc[i];
                    if(newRow>=0 && newRow<n && newCol>=0 && newCol<n && grid[newRow][newCol]==1){
                        components.insert(ds.find_par(newRow*n+newCol));
                    }
                }
                int totalSize=0;
                for(auto it: components){
                    totalSize+=ds.size[it];
                }
                maxi=max(maxi, totalSize+1);
            }
        }
        for(int cellNo=0;cellNo<n*n;cellNo++){
            maxi=max(maxi, ds.size[ds.find_par(cellNo)]);
        }
        return maxi;
    }
};