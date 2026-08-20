class Solution {
public:
    void dfs(int i,vector<vector<int>>&adj,vector<bool>&visited){
        visited[i]=true;
        for(auto next:adj[i]){
            if(!visited[next]){
                dfs(next,adj,visited);
            }
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto i:edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        vector<bool> visited(n,false);
        int count=0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfs(i,adj,visited);
                count++;
            }
        }
        return count;
    }
};
