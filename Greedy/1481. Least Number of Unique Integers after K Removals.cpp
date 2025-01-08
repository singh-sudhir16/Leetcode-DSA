/*
Given an array of integers arr and an integer k. Find the least number of unique integers after removing exactly k elements.

Example 1:

Input: arr = [5,5,4], k = 1
Output: 1
Explanation: Remove the single 4, only 5 is left.
Example 2:
Input: arr = [4,3,1,1,3,3,2], k = 3
Output: 2
Explanation: Remove 4, 2 and either one of the two 1s or three 3s. 1 and 3 will be left.
*/

class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int,int> mp;

        for(int x:arr){
            mp[x]++;
        }
        vector< int > v;

        for(auto it:mp ){
            v.push_back( it.second );
        }

        sort(begin(v),end(v));
        
        for(int i=0 ; i<v.size() ; i++){
            k -= v[i];
            if(k<0)
                return v.size()-i;
        }
        return 0;
    }
};

auto init = []() { 
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0); 
    return 'c'; 
}();

