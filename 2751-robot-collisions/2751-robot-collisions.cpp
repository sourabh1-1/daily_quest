class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n=positions.size();
        vector<vector<int>> robo;
        for(int i=0;i<n;i++){
            robo.push_back({positions[i], healths[i], directions[i], i});
        }
        sort(robo.begin(), robo.end());
        vector<vector<int>> stack;
        for(auto& it: robo){
            if(it[2]=='R' || stack.empty() || stack.back()[2] == 'L'){
                stack.push_back(it);
                continue;
            }
            else{
                bool add=true;
                while(!stack.empty() && stack.back()[2]=='R' && add){
                    if(it[1]<stack.back()[1]){
                        stack.back()[1]--;
                        add=false; 
                    }
                    else if(stack.back()[1]<it[1]){
                        stack.pop_back();
                        it[1]--;
                    }
                    else{
                        stack.pop_back();
                        add=false;
                    }
                }
                if(add)
                    stack.push_back(it);
            }
        }
        vector<int> result;
        sort(stack.begin(), stack.end(), [](vector<int>& a, vector<int>& b) {
            return a[3] < b[3];
        });

        for (auto &robo : stack) {
            result.push_back(robo[1]);
        }

        return result;
    }
};