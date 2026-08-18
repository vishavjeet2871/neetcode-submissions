class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int inf=2147483647;
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0){
                    q.push({i,j});
                }
            }
        }

        vector<vector<int>> dirs={{1,0},{-1,0},{0,1},{0,-1}};

        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();

            for(auto dir:dirs){
                int r=row+dir[0];
                int c=col+dir[1];

                if(r>=n || c>=m || r<0 || c<0 || grid[r][c]!=inf){
                    continue;
                }

                grid[r][c]=grid[row][col]+1;
                q.push({r,c});
            }
        }
        
    }
};
