class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        string initial="";
        string target="123450";
        for(auto row: board){
            for(auto col: row){
                initial+=col+'0';
            }
        }
        vector<vector<int>> swapPos={{1, 3}, {0, 2, 4}, {1, 5}, {0, 4}, {1, 3, 5}, {2, 4}};
        queue<string> q;
        set<string> vis;
        q.push(initial);
        int step=0;
        while(!q.empty()){
            int size=q.size();
            while(size--){
                string res=q.front();
                q.pop();
                if(res==target)
                    return step;
                int zero=-1;
                for(int i=0;i<res.size();i++){
                    if(res[i]=='0'){
                        zero=i;
                        break;
                    }
                }
                for(auto move: swapPos[zero]){
                    string next=res;
                    swap(next[move], next[zero]);
                    if(!vis.count(next)){
                        q.push(next);
                        vis.insert(next);
                    }
                }
            }
            step++;
        }
        return -1;
    }
};