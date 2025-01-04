class Solution {
public:

    // Since the size of palindromic string is 3
    // We only have to check how many unique characters are there
    // between any two matching characters
    // for example
    // a......a
    // answer is 6
    int countPalindromicSubsequence(string s) {
        int n = s.size();
        unordered_set<char> letters;

        for(char c:s)
            letters.insert(c);

        int res = 0; 

        for(char letter:letters) {

            int right_indx = -1;
            int left_indx = -1;

            for(int i=0 ; i<n ; i++) {

                if(s[i]==letter){
                    right_indx = i;
                    if(left_indx==-1)
                        left_indx = i;
                }
            }

            unordered_set<char> chars;

            for(int mid = left_indx+1 ; mid < right_indx ; mid++)
                chars.insert(s[mid]);
            
            res += chars.size();
        }

        return res;
    }
};
auto init = []() { 
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0); 
    return 'c'; 
}();
