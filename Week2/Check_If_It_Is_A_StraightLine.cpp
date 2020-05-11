//https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/535/week-2-may-8th-may-14th/3323/
class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        double  m1 = (double)((double)coordinates[1][1]-(double)coordinates[0][1])/(double)((double)coordinates[1][0]-(double)coordinates[0][0]);
        for(int i=2 ;i<coordinates.size();i++){
            double m2 = (double) ((double)coordinates[i][1]-(double)coordinates[i-1][1])/(double)((double)coordinates[i][0]-(double)coordinates[i-1][0]);
            if(m2!=m1)
                return false;
        }
        return true;
    }
};
