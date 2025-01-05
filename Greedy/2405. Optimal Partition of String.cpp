/*
Given a string s, partition the string into one or more substrings such that the characters in each substring are unique. That is, no letter appears in a single substring more than once.

Return the minimum number of substrings in such a partition.

Note that each character should belong to exactly one substring in a partition.

Example 1:

Input: s = "abacaba"
Output: 4
Explanation:
Two possible partitions are ("a","ba","cab","a") and ("ab","a","ca","ba").
It can be shown that 4 is the minimum number of substrings needed.
*/

class Solution {
public:
    int partitionString(string s) {
        
        unordered_set<char> st;
        int cnt = 0;
        for(char c:s){
            if(st.find(c)==st.end()){
                st.insert(c);
            }
            else {
                st.clear();
                st.insert(c);
                cnt++;
            }
        }

        return cnt+1;
    }
};