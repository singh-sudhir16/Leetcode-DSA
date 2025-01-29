class Solution {
public:
    // 1) store nums1 and nums2 correspondingly and sort in descending order w.r.to nums2
    // 2) take first K-1 elements sum and then multiply it with min
    // 3) make a min heap to store smallest which we will remove as we move forward
    
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        
        vector<pair<int , int>> vec;

        priority_queue<int , vector<int> , greater<>> pq;

        for(int i=0 ; i<nums1.size() ; i++)
            vec.push_back( { nums2[i] , nums1[i]});
        
        sort(rbegin(vec) , rend(vec));

        long long res = 0 , KSum = 0;

        for(int i=0 ; i<=k-1 ; i++){
            KSum += vec[i].second;
            pq.push(vec[i].second);
        }

        res = KSum*vec[k-1].first;

        for(int i=k ; i<nums1.size() ; i++){
            KSum += vec[i].second - pq.top();
            pq.pop();
            pq.push(vec[i].second);
            res = max(res , KSum*vec[i].first);
        }
        return res;
    }
};