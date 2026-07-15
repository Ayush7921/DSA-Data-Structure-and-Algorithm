class Solution {
public:
    int gcdOfOddEvenSums(int n) {

        int oddsum = pow(n,2);
        int evensum = n*(n+1);

        return gcd(oddsum , evensum);

        
    }
};