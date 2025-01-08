class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        long long sum = accumulate(begin(nums) , end(nums) , 0LL);
        sort(begin(nums),end(nums));
        for(int i=nums.size()-1 ; i>=0 ; i--){
            if(sum-nums[i] > nums[i])
                return sum;
            sum -= nums[i]*1LL;
        }
        return -1;
    }
};

auto init = []() { 
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0); 
    return 'c'; 
}();
