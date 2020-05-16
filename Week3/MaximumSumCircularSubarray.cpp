//https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/536/week-3-may-15th-may-21st/3330/
class Solution {
public:
    int kadane(vector<int> A,int n){
         int maxSoFar = -6000000;
        int maxEnding = 0;
        // int size = A.size();
        
        for(int i = 0;i<n;i++){
            maxEnding += A[i];
            if(maxEnding>maxSoFar){
               maxSoFar =maxEnding;
            }
            if(maxEnding<0)
                maxEnding = 0;
        }
        return maxSoFar;
    }
    int maxSubarraySumCircular(vector<int>& A) {
    
        int size = A.size();
        int ans = kadane(A,size);
        int prefix_Sum = 0;
        
        for(int i= 0;i<A.size();i++){
            prefix_Sum +=A[i];
            A[i] = -A[i];
        }   
        int ans2 = prefix_Sum + kadane(A,size-1);
        cout<<ans<<" "<<ans2;
        if(ans2>ans)
            return ans2;
        
        return ans;
    }
};
