class Solution {
public:
    int minDeletions(string s) {
        
        vector<int> freq(26,0);

        for(char c:s)
            freq[c-'a']++;
        
        unordered_set<int> st;
        int res = 0;
        for(int i=0 ; i<26 ; i++){
            while(freq[i]!=0 && st.find(freq[i]) != st.end()){
                    freq[i]--;
                    res++;
            }
            if(freq[i]>0)
            st.insert(freq[i]);
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
