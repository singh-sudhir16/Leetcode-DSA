class Solution {
    public:
        int n;
        string res = "";
        
        string solve(vector<string>& nums , string &path , int indx , unordered_set<string> numSet){
    
            if(indx == n){
                if( numSet.find(path) == numSet.end())
                    return path;
                return "";
            }
            // Start string from existing index 
            for(int i = indx  ; i<n ; i++){
    
                path.push_back('0');
                string temp = solve(nums , path , indx + 1 , numSet);
                if(!temp.empty())
                    return temp;
                path.pop_back();
    
                path.push_back('1');
                string temp2 = solve(nums , path , indx + 1 , numSet);
                if(!temp2.empty())
                    return temp2;
    
                path.pop_back();
            }
            return "";
        }
        string findDifferentBinaryString(vector<string>& nums) {
            n = nums.size();
            string path = "";
            unordered_set<string> numSet(nums.begin(), nums.end());
            return solve(nums , path , 0 , numSet);
            
        }   
    };