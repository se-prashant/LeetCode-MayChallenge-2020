//https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/535/week-2-may-8th-may-14th/3325/
class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
       bool visited[N+1] ;
        int trusty[N+1] ;
        memset(visited,false,sizeof(visited));
        memset(trusty,0,sizeof(trusty));
        for(int i=0;i<trust.size();i++){
            visited[trust[i][0]] = true;
            trusty[trust[i][1]]++;
        }
        for(int i=1;i<=N;i++){
            if(visited[i]==false){
                if(trusty[i]==(N-1))
                    return i;
            }
        }
        return -1;
    }
};
