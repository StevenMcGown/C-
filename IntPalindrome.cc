class IntPalindrome {
public:
    bool isPalindrome(int x) {
        long int check = x;
        long int ans = 0;
        if (x<0) { 
            return false; // Negative numbers cannot be palindromes
        }
        while (x) {
            ans = (ans*10) + (x%10);
            x/=10;
            if (ans>INT_MAX)
                return false;
            if (ans<INT_MIN)
                return false;
        }
        return (ans == check);
    }
};
