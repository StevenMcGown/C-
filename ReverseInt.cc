class ReverseInt {
public:
    int reverse(int x) {
        long int ans=0; // long int range is 32 bit, long long is 64 bit
        if(ans>INT_MAX)
           return 0;
        else if(ans<INT_MIN)
           return 0;
        while(x) // While x != 0 
        {
            ans=(ans*10) +(x%10); 
            x/=10;
        }
        return ans;
    }
};
/*
ANS X
3   12
32  1
321 0
*/
