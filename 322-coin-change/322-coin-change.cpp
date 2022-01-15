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
        
        //return -1;
        
        
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>> dp(n+1,vector<int> (amount+1,-1));
        int x=helper(n,coins,amount,dp);
        return x==INT_MAX-100?-1:x;
    }
};