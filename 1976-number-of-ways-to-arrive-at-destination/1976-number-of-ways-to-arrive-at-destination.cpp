class Solution {
public:
    int mod = 1e9+7;
    int countPaths(int n, vector<vector<int>>& roads) {
        long long src =0;
        priority_queue< pair<long long,long long> , vector<pair<long long,long long>> ,greater<pair<long long,long long>> > pq;
        pq.push({0,0});
        vector<pair<long long,long long>> adj[n];
        for(auto it : roads){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        vector<long long> dist(n,LLONG_MAX);
        dist[src]=0;
        vector<long long> ways(n,0);
        ways[src]=1;

        while(!pq.empty()){
            long long dis = pq.top().first;
            long long node = pq.top().second;

            pq.pop();

            for(auto it : adj[node]){
                long long adjNode = it.first;
                int adjwt = it.second;

                if(dis + adjwt < dist[adjNode]){
                    dist[adjNode] = dis + adjwt;
                    pq.push({dis+adjwt , adjNode});
                    ways[adjNode] = ways[node];
                }

                else if(dis + adjwt  == dist[adjNode]){
                    ways[adjNode] = (ways[adjNode]+ways[node])%mod;
                }
            }

        }
        return ways[n-1]%mod;
    }
};