class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int , int> mp;

        for(int x:nums)
            mp[x]++;
        
        priority_queue<pair<int,int>> pq;

        for(auto x:mp){
            pq.push({ x.second , x.first});
        }

        vector<int> res;
        while(k--){
            auto [i,j] = pq.top();
            pq.pop();
            res.push_back(j);
        }
        return res;
    }
};