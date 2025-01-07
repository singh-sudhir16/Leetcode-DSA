class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        
        int n = words.size();
        vector<string> res;
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<n ; j++){
                if(j==i)
                    continue;
                if(words[j].find(words[i])!=string::npos){
                    res.push_back(words[i]);
                    break;
                }
            }
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
