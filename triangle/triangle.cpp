class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int i=0,j=0,n=triangle.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return helper(i,j,n,triangle,dp);
    }
    int helper(int i,int j,int n,vector<vector<int>> &triangle,vector<vector<int>> &dp){
        if(i==n){
            // last row
            
            return 0;

        }
        if(dp[i][j]!=-1)
            return dp[i][j];
        int a=helper(i+1,j,n,triangle,dp),b=INT_MAX;
        
            
            b=helper(i+1,j+1,n,triangle,dp);
        return dp[i][j]=triangle[i][j]+min(a,b);
    }
};