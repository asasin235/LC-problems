class Solution {
public:
    int helper(int idx,vector<int> &coins,int amount,vector<vector<int>> &dp){
        if(amount==0)
            return 0;
        if(idx<=0)
            return INT_MAX-100;
        if(dp[idx][amount]!=-1){
            return dp[idx][amount];
        }
        if(coins[idx-1]<=amount){
            int take=helper(idx,coins,amount-coins[idx-1],dp)+1;
            int notTake=helper(idx-1,coins,amount,dp);
            return dp[idx][amount]= min(take,notTake);
        }else{
            return dp[idx][amount]= helper(idx-1,coins,amount,dp);
        }
         
    }
    
    
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>> dp(n+1,vector<int> (amount+1));
        dp[0][0]=0;
        for(int i=1;i<=amount;i++){
            dp[0][i]=INT_MAX-100;
        }
        for(int i=0;i<=n;i++){
            dp[i][0]=0;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=amount;j++){
                if(coins[i-1]>j){
                    // not take
                    dp[i][j]=dp[i-1][j];
                }else{
                    dp[i][j]=min(dp[i-1][j],1+dp[i][j-coins[i-1]]);
                }
            }
        }
        if(dp[n][amount]==INT_MAX-100){
            return -1;
        }
       return dp[n][amount];
        // int x=helper(n,coins,amount,dp);
        // return x==INT_MAX-100?-1:x;
    }
};