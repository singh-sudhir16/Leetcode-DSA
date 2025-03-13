/*
    Using binary search 
    we decide whether to move on left or right side , by checking which is the greater element
    We move to right half if the right element is greater
*/

class Solution {
    public:
        int peakIndexInMountainArray(vector<int>& arr) {
            
            int n = arr.size();
            int low = 0 , high = n-1;
    
            while(low<=high){
                int mid = low + (high-low)/2;
                
                if(mid>0 && mid<n-1 && arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1])
                    return mid;
                if(mid>0 && arr[mid-1] > arr[mid])
                    high = mid-1;
                else
                    low = mid+1;
            }
            return -1;
        }
    };