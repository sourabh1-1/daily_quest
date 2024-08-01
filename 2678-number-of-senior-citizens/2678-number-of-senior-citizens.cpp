class Solution {
public:
    int countSeniors(vector<string>& details) {
        int count=0;
        for(int i=0;i<details.size();i++){
            int age=0;
            string s=details[i];
            int digit=s[11]-'0';
            age=age*10+digit;
            digit=s[12]-'0';
            age=age*10+digit;
            if(age>60)
                count++;
        }
        return count;
    }
};