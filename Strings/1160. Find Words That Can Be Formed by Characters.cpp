class Solution {
public:
    int res = 0;
    int countCharacters(vector<string>& words, string chars) {
        
        vector<int> freq(26,0);

        for(char ch:chars)
            freq[ch-'a']++;
        
        for(string word:words){

            vector<int> wordFreq(26,0);

            for(char c:word)
                wordFreq[c-'a']++;

            int size = word.size();

            for(int i=0 ; i<26 ; i++)
                if(wordFreq[i] > freq[i]){
                    size = 0;
                    break;
                }
            
            res += size;
        }
        return res;
    }
};