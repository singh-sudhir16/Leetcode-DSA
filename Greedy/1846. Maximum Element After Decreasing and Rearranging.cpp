class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        
        sort(begin(arr),end(arr));
        arr[0] = 1;
        for(int i=0 ; i<arr.size()-1 ; i++){
            if(arr[i+1] - arr[i] > 1){
                arr[i+1] = arr[i] + 1;
            }
        }
        return arr[arr.size()-1];
    }
};

auto init = []() { 
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0); 
    return 'c'; 
}();


