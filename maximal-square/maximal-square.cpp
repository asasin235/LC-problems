class Solution {
public:
     int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        
        vector<vector<int>> dp(m, vector<int>(n, 0));
        
        
        int ret = 0;
        for(int i = 0 ; i  < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(matrix[i][j] == '1')
                {
                    
                    if(i && j)
                        dp[i][j] = 1 + min(dp[i-1][j-1], min(dp[i][j-1],dp[i-1][j]));
                    else
                        dp[i][j] = 1;
                    
                    ret = max(ret, dp[i][j]);
                }
            }
        }
        
        
        return ret*ret;
        
    }
};