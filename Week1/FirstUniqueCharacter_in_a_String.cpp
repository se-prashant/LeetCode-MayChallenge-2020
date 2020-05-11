//https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/534/week-1-may-1st-may-7th/3320/
class Solution {
public:
    int firstUniqChar(string s) {
        int count[26]={0};
        for(int i=0;i<s.length();i++)
            count[s[i]-'a']++;
        for(int i=0;i<s.length();i++)
            if(count[s[i]-'a']==1)
                return i;
        return -1;
    }
};
