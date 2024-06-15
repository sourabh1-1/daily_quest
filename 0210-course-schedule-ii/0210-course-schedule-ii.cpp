class Solution {
private:
    bool dfs(int node, unordered_map<int, vector<int>> &adj, vector<int> &vis, vector<int> &pvis){
        vis[node]=1;
        pvis[node]=1;
        for(auto it:adj[node]){
            if(!vis[it]){
                if(dfs(it, adj, vis, pvis))
                    return true;
            }
            else if(pvis[it])
                return true;
        }
        pvis[node]=0;
        return false;
    }
    void topo(int node, unordered_map<int, vector<int>> &adj, vector<int> &vis, stack<int> &st){
        vis[node]=1;
        for(auto it: adj[node]){
            if(!vis[it]){
                topo(it, adj, vis, st);
            }
        }
        st.push(node);
    }
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> ans;
        unordered_map<int, vector<int>> adj;
        for(int i=0;i<prerequisites.size();i++){
            int a=prerequisites[i][0];
            int b=prerequisites[i][1];
            adj[b].push_back(a);
        }
        vector<int> vis(numCourses, 0);
        vector<int> pvis(numCourses, 0);
        for(int i=0;i<numCourses;i++){
            if(!vis[i]){
                if(dfs(i, adj, vis, pvis))
                    return {};
            }
        }
        stack<int> st;
        vis.assign(numCourses, 0);
        for(int i=0;i<numCourses;i++){
            if(!vis[i])
                topo(i, adj, vis, st);
        }
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};