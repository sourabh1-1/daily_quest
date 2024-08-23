class Solution {
public:
    string fractionAddition(string expression) {
        int num=0;
        int den=1;
        int c=0;
        while(c<expression.size()){
            int sign=1;
            if(expression[c]=='-' || expression[c]=='+'){
                if(expression[c]=='-')
                    sign=-1;
                c++;
            }
            int n=0;
            while(isdigit(expression[c])){
                n=n*10+(expression[c]-'0');
                c++;
            }
            n*=sign;
            c++;
            int d=0;
            while(isdigit(expression[c])){
                d=d*10+(expression[c]-'0');
                c++;
            }
            num=d*num+den*n;
            den*=d;
            int val=gcd(num, den);
            num/=val;
            den/=val;
        }
        return to_string(num)+'/'+to_string(den);
    }
};