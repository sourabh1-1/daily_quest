class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int, int>> adj[n+1];
        for(auto it: times){
            adj[it[0]].push_back({it[1], it[2]});
        }
        vector<int> dist(n+1, INT_MAX);
        queue<pair<int, int>> q;
        q.push({0, k});
        dist[k]=0;
        int maxi=0;
        while(!q.empty()){
            int time=q.front().first;
            int node=q.front().second;
            q.pop();
            for(auto it: adj[node]){
                int adjNode=it.first;
                int newTime=it.second;
                if(dist[adjNode]>time+newTime){
                    dist[adjNode]=time+newTime;
                    q.push({time+newTime, adjNode});
                }
            }
        }
        for(int i=1;i<=n;i++){
            maxi=max(maxi, dist[i]);
        }
        return maxi==INT_MAX?-1:maxi;
    }
};