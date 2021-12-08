class Solution {
public:
    void dfs(vector<vector<char>> &grid,int i,int j,vector<vector<bool>> &visited,int m,int n){
        visited[i][j]=true;
        if(i+1<m and !visited[i+1][j] and grid[i+1][j]=='1')
            dfs(grid,i+1,j,visited,m,n);
    
    if(i-1> -1  and !visited[i-1][j] and grid[i-1][j]=='1')
            dfs(grid,i-1,j,visited,m,n);
    
if(j+1<n and !visited[i][j+1] and grid[i][j+1]=='1')
            dfs(grid,i,j+1,visited,m,n);
    
if(j-1>-1 and !visited[i][j-1] and grid[i][j-1]=='1')
            dfs(grid,i,j-1,visited,m,n);
    
}
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        int cnt=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++)
            {
                if(visited[i][j]==false and grid[i][j]=='1'){
                    cnt++;
                    dfs(grid,i,j,visited,m,n);
                }
            }
        }
        return cnt;
    }
};