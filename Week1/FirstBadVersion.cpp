//https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/534/week-1-may-1st-may-7th/3316/
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int min = 1;
        int start = 1;
        int end = n;
    
        while(start<=end){
            int mid = (start)+(end-start)/2;
            if(isBadVersion(mid)){
                end = mid-1;
                min = mid;
            }else{
                start  = mid+1;
            }
        }
        return min;
    }
};
