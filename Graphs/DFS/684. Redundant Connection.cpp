class Solution {
public:
   
    bool dfs(vector<vector<int>> &adj , int u , int parent , vector<bool> &vis){
        vis[u] = true;

        for(int v:adj[u]){
            if(v==parent){
                continue;
            }
            if(vis[v]){
                // res = {u,v};
                return true;
            }
            if(!vis[v] && dfs(adj , v , u , vis)){
                return true;
            }
        }

        return false;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        
        int m = edges.size();
        
        vector<vector<int>> adj(m+1);
        int i = 0;
        for(auto vec:edges){
            int u = vec[0];
            int v = vec[1];

            adj[u].push_back(v);
            adj[v].push_back(u);

            vector<bool> vis(m+1,false);
        
            if(dfs(adj , u , -1 , vis))
                return edges[i];

            i++;
        }
        

        return {};
    }
};