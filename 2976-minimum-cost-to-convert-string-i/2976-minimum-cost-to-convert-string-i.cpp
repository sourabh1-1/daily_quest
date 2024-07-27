class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector<vector<int>> graph(26, vector<int>(26, INT_MAX));
        for(int  i=0;i<26;i++){
            graph[i][i]=0;
        }
        for(int i=0;i<original.size();i++){
            graph[original[i]-'a'][changed[i]-'a']=min(graph[original[i]-'a'][changed[i]-'a'], cost[i]);
        }
        for(int k=0;k<26;k++){
            for(int i=0;i<26;i++){
                if(graph[i][k]<INT_MAX){
                    for(int j=0;j<26;j++){
                        if(graph[k][j]<INT_MAX){
                            graph[i][j]=min(graph[i][j], graph[i][k]+graph[k][j]);
                        }
                    }
                }
            }
        }
        long long totalCost=0;
        for(int i=0;i<source.size();i++){
            int from=source[i]-'a';
            int to=target[i]-'a';
            if(from!=to){
                if(graph[from][to]==INT_MAX)
                    return -1;
                totalCost+=graph[from][to];
            }
        }
        return totalCost;
    }
};