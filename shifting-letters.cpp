// https://leetcode.com/problems/shifting-letters/
class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        // we can observe that the last char will be shifted only the number of times the last value in shifts arr
        // so wecan use a suffixsum to find the number of shifts for eah char
        vector<long long>suffixShifts(s.size());
        long long curShifts = 0;
        for(int i = shifts.size() - 1 ; i>=0 ;i--){
            curShifts += shifts[i];
            suffixShifts[i] = curShifts%26;
            // shifting anything 26 times means coming to the same letter so apply mod
        }
        // shift each character the number of times in suffixShifts
        for(int i=0;i<s.size();i++){
            char c = s[i];
            // if the current char + shifts is more than z (122) than we add the remaining diff char + shifts - 123 (123 because one shift will be going to a)
            if((int)c + suffixShifts[i] > 122){
                c = 'a' + ((int)c + suffixShifts[i] - 123);
            }
            // else we can directly shift the char
            else{
                c = c + suffixShifts[i];
            }            
            s[i] = c;
        }
        return s;
    }
};
