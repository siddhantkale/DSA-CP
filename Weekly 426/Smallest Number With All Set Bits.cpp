https://leetcode.com/problems/smallest-number-with-all-set-bits
class Solution {
public:
    // The smallest number with all set bits with the required condition
    // will be the number just before the next power
    int smallestNumber(int n) {
        
        return pow(2,floor(log2(n))+1) - 1;
        }
    };
