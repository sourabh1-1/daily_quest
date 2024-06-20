class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int, int>> adj[n];
        for(int i=0;i<flights.size();i++){
            adj[flights[i][0]].push_back({flights[i][1], flights[i][2]});
        }
        queue<pair<int, pair<int, int>>> q;
        q.push({0, {src, 0}});
        vector<int> dist(n, INT_MAX);
        while(!q.empty()){
            int step=q.front().first;
            int node=q.front().second.first;
            int cost=q.front().second.second;
            q.pop();
            if(step>k)
                continue;
            for(auto it: adj[node]){
                int adjNode=it.first;
                int edgeCost=it.second;
                if(cost+edgeCost<dist[adjNode] && step<=k){
                    dist[adjNode]=cost+edgeCost;
                    q.push({step+1, {adjNode, cost+edgeCost}});
                }
            }
        }
        if(dist[dst]==INT_MAX)
            return -1;
        return dist[dst];
    }
};