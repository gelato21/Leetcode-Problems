class Solution {
public:    
    int getBitCount(int n)
    {
        int count = 0;
        while(n) {
            count++;
            n = n >> 1;
        }
        return count;
    }    
    int minimumOneBitOperations(int n)
    {
        // base cases
        if(n == 0)
            return 0;
        if(n == 1)
            return 1;

        // get number of bits required to represent n
        int bitCount = getBitCount(n);
        // the pattern required to convert current bit to zero is 10000...
        // where 1 is at one pos before the msb of n
        int requiredPattern = (1 << (bitCount - 2));
        // the remaining msb after converting msb of n to zero
        int remainingNum = n ^ (1 << (bitCount - 1));        

        return 2 * minimumOneBitOperations(requiredPattern) - minimumOneBitOperations(remainingNum) + 1;
    }    
};