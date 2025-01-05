class Solution {
public:
    /*
        FACT 1 : If we break a number into N parts then require N-1 operations ( Considering the fact that we can only break a number into 2 parts)

        FACT 2 : [9,7,6] If we break 7 It can be broken into
        1,6
        2,5
        3,4
        But 3,4 is the optimal choice . we replace 7 by 3,4
        for next number that is i-1th indx our interest of number is 3 (to maintain 3 , 4 increase order)
        We get 3 by dividing 7 by the no. of parts we are dividing it (7/2) 

        FACT 3 : No. of parts required will be nums[i] / nums[i+1] + 1 (If the nums[i] is not perfectly divisible by nums[i+1] )
        Consider the case 7,6
        we divide 7 into 3,4 (2)parts 
        How do we get it 7/6 = 1 + 7%6

    */
    long long minimumReplacement(vector<int>& nums) {
        int n = nums.size();
        long long operations = 0;
        for(int i=n-2 ; i>=0 ; i--){

            if(nums[i]<=nums[i+1])
                continue;
            
            int parts = nums[i]/nums[i+1];
            if(nums[i]%nums[i+1]!=0)
                parts++;
            
            operations += parts-1;
            nums[i] = nums[i] / parts;
        }
        return operations;
    }
};

auto init = []() { 
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0); 
    return 'c'; 
}();
