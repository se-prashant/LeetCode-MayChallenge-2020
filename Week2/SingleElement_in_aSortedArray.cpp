//https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/535/week-2-may-8th-may-14th/3327/
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int start,end;
        start = 0;
        end = nums.size()-1;
        int n= end;
        if(end==0)
            return nums[0];
        while(start<=end){
            int mid = start+(end-start)/2;
            if(mid==0){
                if(nums[mid]!=nums[mid+1])
                    return nums[mid];
                else 
                    start = mid+2;
            }else if(mid==(n)){
                if(nums[mid]!=nums[mid-1])
                    return nums[mid];
                else 
                    end = mid-1;
            }
            else{
                if(nums[mid]!=nums[mid+1] && nums[mid]!=nums[mid-1])
                    return  nums[mid];
            }
            
            if(mid%2){
                if(nums[mid]==nums[mid-1])
                    start = mid+1;
                else
                    end = mid-1;
            }else{
                if(nums[mid]==nums[mid-1])
                    end = mid-2;
                else
                    start = mid+2;
            }
        }
        return -1;
    }
};
