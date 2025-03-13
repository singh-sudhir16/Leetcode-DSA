/*
    To find peak element in Log(N) time
    It can be solved by binary search
    We decide whether to move in the left half or the right half by checking  which is the greater element
    If the right element is greater than the current mid element , 
    than the peak element will always lie on the right side ( if the peak element is Unique).
    
*/

class Solution {
    public:
        int findPeakElement(vector<int>& nums) {
          if(nums.size() == 1) return 0; 
            int n = nums.size();
            if(nums[0] > nums[1]) return 0;
            if(nums[n-1] > nums[n-2]) return n-1;
    
            int left=1 , right=n-2;
            while(left<=right)
            {
                  int mid = left + (right-left)/2;
    
                    if(nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1]) 
                        return mid;
                    else if(nums[mid] < nums[mid-1]) 
                        right = mid - 1;
                    else  
                        left = mid + 1;
            } 
    
            return -2;
        }
    };