class Solution {
    public:
        vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
            unordered_map<int , int> mp; // to store the answers for each element
    
            stack<int> st;
            int n = nums2.size();
            for(int i=n-1 ; i>=0 ; i--){
    
                while(!st.empty() && st.top()<=nums2[i]){
                    st.pop();
                }
                int res = st.empty() ? -1 : st.top();
                st.push(nums2[i]);
                mp[nums2[i]] = res;
            }
    
            vector<int> res;
    
            for(int x:nums1){
                res.push_back(mp[x]);
            }
            return res;
        }
    };