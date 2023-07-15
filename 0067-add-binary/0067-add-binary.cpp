class Solution {
public:
    string addBinary(string a, string b) {
        int n1=a.length()-1;
        int n2=b.length()-1;
        int c=0;
        string ans="";
        while(n1>=0 || n2>=0 || c>0){
            int x = (n1 >= 0) ? a[n1--] - '0' : 0;
            int y = (n2 >= 0) ? b[n2--] - '0' : 0;
            int sum = x + y + c;
            ans=to_string((x+y+c)%2)+ans;
            c=(x+y+c)/2;
        }
        return ans;
    }
};