class Solution {
public:
    using p = pair<int , pair<int , int>>;

    vector<vector<int>> dirs = {  {0,1} , {1,0} , {1,1} , {0,-1} , {-1,0} , {-1,-1} , {-1,1} , {1,-1}};
    

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        if(m==0 || n==0 || grid[0][0]==1)
            return -1;
        priority_queue<p , vector<p> , greater<p>> pq;

        vector<vector<int>> res(n , vector<int> (m , INT_MAX));
        res[0][0] = 0;
        pq.push({0 , {0,0}});
        
        auto isSafe = [&](int x , int y){
            return x>=0 && x<n && y>=0 && y<m;
        };

        while(!pq.empty()){
            
            int d = pq.top().first;
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            
            pq.pop();
            
            for(auto dir:dirs){
                int _x = x + dir[0];
                int _y = y + dir[1];

                if(isSafe(_x , _y) && grid[_x][_y]==0 && 1+d < res[_x][_y]) {
                    pq.push({1+d , { _x , _y }});
                    res[_x][_y] = 1 + d;
                    grid[_x][_y] = 1;
                }
            }
        }

        return res[n-1][m-1] == INT_MAX ? -1 : res[n-1][m-1] + 1 ;
    }
};

auto init = []()
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();