//https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/536/week-3-may-15th-may-21st/3332/
class Solution {
public:
    bool compare(int arr1[],int arr2[]) 
    { 
        
        for (int i=0; i<26; i++) {
        // cout<<arr1[i]<<" "<<arr2[i]<<endl;
            if (arr1[i] != arr2[i])
                return false; 
        }
        return true; 
    } 
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        if(s.length()<p.length())
            return ans;
        int p_count[26] = {0};
        
        
        int s_count[26] = {0};
        for(int i= 0;i<p.length();i++){
            p_count[p[i]-'a']++;  
            
        }
        for(int i= 0;i<p.length();i++){
            s_count[s[i]-'a']++;    
        }
     
        
        for(int j=p.length(); j<s.length() ;j++){
            if(compare(p_count,s_count)){
                ans.push_back(j-p.length());
            }
            s_count[s[j]-'a']++;
            s_count[s[j-p.length()]-'a']--;
        }
        if(compare(p_count,s_count))
            ans.push_back(s.length()-p.length());
        return ans;
    }
};
