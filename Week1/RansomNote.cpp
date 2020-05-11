//https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/534/week-1-may-1st-may-7th/3318/
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int countRansom[26] = {0};
        int countMagazine[26] = {0};
        for(int i=0;i<ransomNote.length();i++){
            countRansom[ransomNote[i]-'a']++;    
        }
        for(int i=0;i<magazine.length();i++){
            countMagazine[magazine[i]-'a']++;    
        }
        for(int i=0;i<26;i++){
            if(countRansom[i]==0)
                continue;
            if(countRansom[i]>countMagazine[i])
                return false;
        }
        return true;
    }
};
