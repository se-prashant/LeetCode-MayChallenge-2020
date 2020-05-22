//https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/536/week-3-may-15th-may-21st/3336/
class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int dp[n][m] ;
        for(int i =0;i<n;i++){
            for(int j =0;j<m;j++)
                dp[i][j] = 0;
        }
        int ans = 0;
        for(int i=0;i<m;i++){
            dp[0][i] = matrix[0][i];
            ans+= dp[0][i];
        }
        for(int i=1;i<n;i++){
            dp[i][0] = matrix[i][0];
            ans+=dp[i][0];
        }
        for(int i =1;i<n;i++){
            for(int j = 1;j<m;j++){
                if(matrix[i][j]==0) continue;
                if(dp[i-1][j]==0 || dp[i-1][j-1]==0 || dp[i][j-1]==0){
                    dp[i][j] = 1;
                     ans+=dp[i][j];
                
                    continue;
                }
                if(dp[i-1][j]==dp[i-1][j-1] && dp[i-1][j-1]==dp[i][j-1]){
                    dp[i][j] = dp[i-1][j]+1;
                    ans+=dp[i][j];
                }
                else{
                    int _min = min(dp[i-1][j],min(dp[i-1][j-1],dp[i][j-1]));
                    dp[i][j]  =1+ _min;
                    ans+=dp[i][j];
                }
            }
        }
      
        return ans;
    }
};
