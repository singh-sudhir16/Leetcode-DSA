class Solution {
public:
    char kthCharacter(int k) {
        string word="a";

        while(word.size()<k){
            string tmp = word;
            for(char &c:tmp){
                 c = 'a' + (c - 'a' + 1) % 26;
            }
            word = word + tmp;
        }
        return word[k-1];
    }
};