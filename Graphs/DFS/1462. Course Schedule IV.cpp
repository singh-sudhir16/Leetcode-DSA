class Solution {
public:

    bool dfs(int u , int v , unordered_map<int, vector<int>> &adj , vector<bool> &visited){
        visited[u] = true;

        for(int x:adj[u]){
            if(x==v)
                return true;
        }
    }

    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {

        unordered_map<int , vector<int>> adj;

        for(auto vec:prerequisites){
            int u = vec[0];
            int v = vec[1];

            adj[v].push_back(u);
        }   
        int i=0;
        for(auto q:queries){
            int uj = q[0];
            int vj = q[1];
            vector<bool> visited(n , false);
            res[i] = dfs(uj , vj , adj , visited);
        }
    }
};