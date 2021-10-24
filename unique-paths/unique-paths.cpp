class Solution {
public:
    int uniquePaths(int m, int n) {
        int curX=0,curY=0;
        vector<vector<int> > v(n,vector<int> (m,-1));
    
        return helper(curX,curY,m,n,v);
        
    }
    int helper(int curX,int curY,int m,int n,vector<vector<int>> &v){
        if(curX==n-1 and curY==m-1){
            return 1;
        }
        if(curX>=n or curY>= m){
            return 0;
        }
        if(v[curX][curY]!=-1){
            return v[curX][curY];
        }
        int down=helper(curX,curY+1,m,n,v);
        int right =helper(curX+1,curY,m,n,v);
        v[curX][curY]=down+right;
        return down +right;
        
    }
};