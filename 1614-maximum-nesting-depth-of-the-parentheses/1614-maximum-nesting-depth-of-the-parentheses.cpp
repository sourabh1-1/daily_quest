class Solution {
public:
    int maxDepth(string s) {
        int maxP=0;
        int P=0;
        for(char c:s){
            if(c=='('){
                P++;
                maxP=max(maxP,P);
            }
            else{
                if(c==')')
                    P--;
            }
        }
        return maxP;
    }
};