class Solution {
public:
    double myPow(double x, int n) {
        double result=1.0;
        if(n<0){
            x=1/x;
            n=abs(n);
        }
        while(n>0){
            if(n%2==0){
                x=x*x;
                n=n/2;
            }
            else{
                result=result*x;
                n--;
            }
        }
        return result;
    }
};