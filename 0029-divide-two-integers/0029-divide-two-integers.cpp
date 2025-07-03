class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend==divisor){
            return 1;
        }
        bool sign=true;
        if(dividend>=0 && divisor<0) sign=false;
        if(dividend<0 && divisor>0) sign=false;
        long long n=abs((long long)dividend);
        long long d=abs((long long)divisor);
        long q=0;
        while(n>=d){
            int count=0;
            while(n>=(d<<(count+1))){
                count++;
            }
            q+=(1LL<<count);
            n=n-d*(1LL<<count);
        }
        if(q>INT_MAX){
            return sign ? INT_MAX:INT_MIN;
        }
        return sign ? q:-q;
    }
};