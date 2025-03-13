class Solution {
    public:
        int findMin(vector<int>& v) {
            int n = v.size();
            int low = 0, high = n - 1;
    
            while (low <= high) {
                
                if (v[low] <= v[high]) return v[low]; // If the array is already sorted
    
                int mid = low + (high - low) / 2;
                int next = (mid + 1) % n;
                int prev = (mid + n - 1) % n;
    
                if (v[mid] <= v[next] && v[mid] <= v[prev]) 
                    return v[mid];
    
                
                if (v[mid] >= v[low]) 
                    low = mid + 1;
                else  
                    high = mid - 1;
            }
            return -1;
        }
    };
    