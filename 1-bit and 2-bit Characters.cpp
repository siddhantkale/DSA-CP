https://leetcode.com/problems/1-bit-and-2-bit-characters/description/
class Solution {
public:
    // use a pointer if the current bit is 0 it will be 1st char
    // if the current bit is 1 then that and the next bit will be of 2nd char so move to i+2
    // if the ptr reaches at the last element it has to be 0
    // else not possible
    bool isOneBitCharacter(vector<int>& bits) {
        int i=0;
        while(i<bits.size()){
            if(i==bits.size()-1){
                return true;
            }
            if(bits[i]==0)i++;
            else i+=2;
        }
        return false;
    }
};
