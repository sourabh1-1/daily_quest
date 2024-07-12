class Solution {
    int points=0;
public:
    int maximumGain(string s, int x, int y) {
        int totalpoints=0;
        if(x<y){
            int temp=x;
            x=y;
            y=temp;
            reverse(s.begin(), s.end());
        }
        int a_count=0;
        int b_count=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='a')
                a_count++;
            else if(s[i]=='b'){
                if(a_count>0){
                    totalpoints+=x;
                    a_count--;
                }
                else
                    b_count++;
            }
            else{
                totalpoints+=min(a_count, b_count)*y;
                a_count=0;
                b_count=0;
            }
        }
        totalpoints+=min(a_count, b_count)*y;
        return totalpoints;
    }
};