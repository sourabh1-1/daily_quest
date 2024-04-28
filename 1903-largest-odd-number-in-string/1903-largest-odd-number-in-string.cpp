class Solution {
public:
    string largestOddNumber(string num) {
        int end = num.size()-1;
        while(end>=0){
            int digit = num[end]-'0';
            if(digit%2==0){
                end--;
            }
            else{
                string result = num.substr(0,end+1);
                return result;
            }
        }
        return "";
    }
};