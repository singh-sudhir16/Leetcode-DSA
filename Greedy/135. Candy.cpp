/*
There are n children standing in a line. Each child is assigned a rating value given in the integer array ratings.

You are giving candies to these children subjected to the following requirements:

Each child must have at least one candy.
Children with a higher rating get more candies than their neighbors.
Return the minimum number of candies you need to have to distribute the candies to the children.

Example 1:

Input: ratings = [1,0,2]
Output: 5
Explanation: You can allocate to the first, second and third child with 2, 1, 2 candies respectively.
*/

// Approach : First check left to right if values are changing by left neighbours then check with right 
//            neighbors and take max of them 

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> res(n,1); 

        for(int i=1 ; i<n ; i++){
            if(ratings[i] <= ratings[i-1])
                continue;
            res[i] = res[i-1]+1;
        }

        for(int i=n-2 ; i>=0 ; i--){
            if(ratings[i] <= ratings[i+1])
                continue;
            res[i] = max(res[i] ,res[i+1]+1);
        }
        
        return accumulate(begin(res) , end(res),0);
    }
};

auto init = []() { 
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0); 
    return 'c'; 
}();
