class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n = speed.size();
        for(int i=0 ; i<n ; i++){
            dist[i] = ceil(dist[i]*1.0/speed[i]*1.0);
        }
        sort(begin(dist),end(dist));
        int res = 1;
        for(int i=1 ; i<n ; i++){
            if((dist[i]-i)>0)
                res++;
            else
                break;
        }
        return res;
    }
};

auto init = []() { 
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0); 
    return 'c'; 
}();
