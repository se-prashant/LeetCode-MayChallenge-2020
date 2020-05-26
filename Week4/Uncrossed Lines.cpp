//https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/537/week-4-may-22nd-may-28th/3340/
class Solution {
public:
    int maxUncrossedLines(vector<int>& A, vector<int>& B) {
       int m = A.size();
        int n = B.size();
        int **dp= new int*[m+1];
        
        for(int i=0;i<=A.size();i++){
            dp[i] = new int[n+1];
            for(int j= 0;j<=B.size();j++)
                dp[i][j]= 0;                
        }
        for(int i = 0;i<=m;i++){
            dp[i][0] = 0;
        }
        int res= 0;
        for(int i=0;i<=n;i++) dp[0][i] = 0;
        for(int i =1;i<=m;i++){
            for(int j = 1;j<=n;j++){
               if(A[i-1]==B[j-1])
                    dp[i][j] = (1+dp[i-1][j-1]);
                else{
                     dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                
                }
            }
        }
       return dp[m][n];
     
    }
};
