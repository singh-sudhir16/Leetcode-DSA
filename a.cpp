#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#include <stack>

using namespace std;

#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define pb push_back
#define all(v) v.begin(), v.end()

int main() {
    fast_io;

    // Your code here
    // Example usage of the provided code
    vector<int> nums1 = {4, 1, 2};
    vector<int> nums2 = {1, 3, 4, 2};
    unordered_map<int, int> mp; // to store the answers for each element
    stack<int> st;
    int n = nums2.size();
    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && st.top() <= nums2[i]) {
            st.pop();
        }
        int res = st.empty() ? -1 : st.top();
        st.push(nums2[i]);
        mp[nums2[i]] = res;
    }
    vector<int> res;
    for (int x : nums1) {
        res.push_back(mp[x]);
    }
    // Output the result
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    return 0;
}