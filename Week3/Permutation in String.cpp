//https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/536/week-3-may-15th-may-21st/3333/
class Solution {
public:
    bool isPermutation(int ar1[],int ar2[]){
        for(int i=0;i<26;i++){
          if(ar1[i]!=ar2[i])
               return  false;
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        if(s1.length()>s2.length())
            return false;
        int inS2[26]={0};
        int inS1[26]={0};
       
       for (int i = 0; i < s1.length(); i++) {
            inS1[s1[i] - 'a']++;
            inS2[s2[i] - 'a']++;
        }
        for (int i = 0; i < s2.length() - s1.length(); i++) {
            if (isPermutation(inS1,inS2)) {
                return true;
            }
            inS2[s2[i + s1.length()] - 'a']++;
            inS2[s2[i] - 'a']--;
        }
        return (isPermutation(inS1,inS2));
        return false;
    }
};
