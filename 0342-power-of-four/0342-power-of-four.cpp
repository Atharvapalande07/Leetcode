class Solution {
public:
    bool isPowerOfFour(int n) {

        if (n == 1)
            return true;

        if (n<=0)

            return false;

        double sqrtN = sqrt(n);

        double log2sqrtN = log2(sqrtN);

        return (log2sqrtN == (int) log2sqrtN);



        
    }
};