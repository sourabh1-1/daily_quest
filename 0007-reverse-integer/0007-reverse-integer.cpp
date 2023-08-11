class Solution {
public:
    int reverse(int x) {
        long long int revnum=0;
        int flag=0;
        if(x<0){
            x=abs(x);
            flag=1;
        }
        while(x>0){
            int r=x%10;
            x=x/10;
            revnum=revnum*10+r;
        }
        if(revnum>INT_MAX || revnum<INT_MIN)
            return 0;
        return flag?-revnum:revnum;
    }
};