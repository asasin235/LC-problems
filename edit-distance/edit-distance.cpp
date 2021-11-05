class Solution {
public:
   int minDistance(string word1, string word2) {
        int w1=word1.size(),w2=word2.size();
      vector<vector<int>> dp(w1+1, vector<int>(w2+1, -1));

         dp[w1][w2]= helper(word1,word2,w1,w2,dp);
         return dp[w1][w2];
        }
    int helper(string m ,string n,int w1, int w2, vector<vector<int>> &dp){
         if(w1==0){return dp[w1][w2]= w2;}
         if(w2==0){return dp[w1][w2] =w1;}
      if (dp[w1][w2] != -1) {
            return dp[w1][w2];
        }
    if ( m[w1-1]==n[w2-1]){
            dp[w1][w2]= helper(m,n,w1-1,w2-1,dp);
            return dp[w1][w2];}
        else
    dp[w1][w2]=min(helper(m,n,w1,w2-1,dp),min(helper(m,n,w1-1,w2-1,dp),helper(m,n,w1- 1,w2,dp)))+ 1;
        return dp[w1][w2];
    }
};
