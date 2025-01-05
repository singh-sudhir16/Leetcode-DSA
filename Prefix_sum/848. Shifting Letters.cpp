/*
You are given a string s of lowercase English letters and an integer array shifts of the same length.

Call the shift() of a letter, the next letter in the alphabet, (wrapping around so that 'z' becomes 'a').

For example, shift('a') = 'b', shift('t') = 'u', and shift('z') = 'a'.
Now for each shifts[i] = x, we want to shift the first i + 1 letters of s, x times.

Return the final string after all such shifts to s are applied.
*/

class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        int n = s.size();
        for(int i=n-2 ; i>=0 ; i--){
            shifts[i] += (shifts[i+1])%26;
        }
        for(int i=0; i<s.size() ; i++){
            int tmp = shifts[i];
            
            s[i] = (s[i]-'a' + tmp)%26 + 'a'; 
        }
        return s;
    }
};