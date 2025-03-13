class Solution {
    public:
        char nextGreatestLetter(vector<char>& letters, char target) {
            
            int n = letters.size();
    
            if(letters[0] > target)
                return letters[0];
    
            int low = 0 , high = n-1;
            int pos = -1;
    
            while(low <= high){
                int mid = low + (high-low)/2;
    
                if(letters[mid] > target){
                    pos = mid; // store the current position and check for lesser element
                    high = mid-1;
                }
                else{
                    low = mid+1;
                }
            }
    
            return pos==-1 ? letters[0] : letters[pos];
        }
    };