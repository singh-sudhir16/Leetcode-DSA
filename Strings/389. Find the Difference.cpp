class Solution {
public:
    char findTheDifference(string s, string t) {
        sort(begin(s),end(s));
        sort(begin(t),end(t));

        for(int i=0 ; i<t.size() ; i++){

            if(i<s.size() && s[i]!=t[i])
                return t[i];
        }
        return t[t.size()-1];
    }
};