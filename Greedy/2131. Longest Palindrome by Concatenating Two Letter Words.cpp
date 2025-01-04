class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        
        unordered_map<string , int> mp;

        for(auto x:words)
            mp[x]++;
        
        int res = 0;
        bool centreUsed = false;
        for(auto x:words) {
            string rev = x;
            reverse(begin(x) , end(x));

            if(x == rev){ // "aa" case

                if(mp[x]>1){
                    mp[x]-=2;
                    res += 4;
                }
                else if(mp[x]==1 && centreUsed == false){
                    res += 2;
                    mp[x] -= 1;
                    centreUsed = true;
                }

            }
            else{
                if(mp[x]>0 && mp[rev]>0){
                    res += 4;
                    mp[x]--;
                    mp[rev]--;
                }
            }
        }

        return res;
    }
};