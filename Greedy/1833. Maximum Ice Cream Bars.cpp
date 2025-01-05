/*
It is a sweltering summer day, and a boy wants to buy some ice cream bars.

At the store, there are n ice cream bars. You are given an array costs of length n, where costs[i] is the price of the ith ice cream bar in coins. The boy initially has coins coins to spend, and he wants to buy as many ice cream bars as possible. 

Note: The boy can buy the ice cream bars in any order.

Return the maximum number of ice cream bars the boy can buy with coins coins.

You must solve the problem by counting sort.

Example 1:

Input: costs = [1,3,2,4,1], coins = 7
Output: 4
Explanation: The boy can buy ice cream bars at indices 0,1,2,4 for a total price of 1 + 3 + 2 + 1 = 7.
*/

class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        
        sort(begin(costs),end(costs));
        int cnt = 0;
        for(int x:costs){
            if(x>coins)
                break;
            coins -= x;
            cnt++;
        }
        return cnt;
    }
};