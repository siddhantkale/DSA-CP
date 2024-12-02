// https://leetcode.com/problems/check-if-a-word-occurs-as-a-prefix-of-any-word-in-a-sentence/
class Solution {
public:
    // istringstream is from sstream lib used to only input from string streams
    // so we extract each word remembering it's position
    // use compare function from string class
    // where the first arg is position to start
    // second is length of the string on which func called
    // third is the other string
    int isPrefixOfWord(string sentence, string searchWord) {
        istringstream stream(sentence);
        int len = searchWord.length();
        string word;
        int pos = 1; 
        while(stream >> word){
            if(word.length()>=searchWord.size() && word.compare(0,len,searchWord)==0){
                return pos;
            }
            pos++;
        }
        return -1;
    }
};
