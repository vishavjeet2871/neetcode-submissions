class Solution {
public:
    bool cycle(int cur,unordered_map<int,list<int>>&adj,vector<bool>&vis,int par){
        vis[cur]=true;

        for(auto i:adj[cur]){
            if(vis[i]){
                if(i==par){
                    continue;
                }
                else{
                    return true;
                }
            }
            if(cycle(i,adj,vis,cur)){
                return true;
            }
        }
        return false;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size()!=n-1){
            return false;
        }
        unordered_map<int,list<int>> adj;
        for(auto i:edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        vector<bool> vis(n,false);
        vector<bool> path(n,false);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                if(cycle(i,adj,vis,-1)){
                    return false;
                }
            }
        }
        return true;
    }
};
