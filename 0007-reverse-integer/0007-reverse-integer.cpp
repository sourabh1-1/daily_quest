class Solution {
public:
    int reverse(int x) {
        int flag=0;
        if(x<0){
            x=abs(x);
            flag=1;
        }
        long long int temp=0;
        while(x>0){
            int c=x%10;
            x=x/10;
            temp=temp*10+c;
        }
        if(temp>INT_MAX || temp<INT_MIN)
            return 0;
        return flag?-temp:temp;
    }
};