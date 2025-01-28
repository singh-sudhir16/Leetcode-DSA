class Solution {
public:
    // Topological can applied only when the graph is DAG , we are applying topo sort and checking if
    // all the nodes are visited , if it is so then we finishing courses is possible; 
    bool topoSort(int n , unordered_map<int , vector<int> > &adj , vector<int> &indegree){
        queue<int> q;

        int count = 0;

        for(int i=0 ; i<n ; i++){
            if(indegree[i]==0){
                q.push(i);
                count++;
            }
        }

        while(q.size()){
            int u = q.front();
            q.pop();

            for(int &v:adj[u]){
                indegree[v]--;

                if(indegree[v]==0){
                    count++;
                    q.push(v);
                }
            }
        }

        return count==n;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<int> indegree(numCourses,0);

        unordered_map<int , vector<int> > adj;

        for(auto vec:prerequisites){
            int u = vec[0];
            int v = vec[1];
            
            adj[v].push_back(u);
            indegree[u]++;
        }

        return topoSort(numCourses , adj , indegree);
    }
};