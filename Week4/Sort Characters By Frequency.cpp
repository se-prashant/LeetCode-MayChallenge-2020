//https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/537/week-4-may-22nd-may-28th/3337/
class Solution {
public:
    
    string frequencySort(string s) {
        vector<pair<int,int>> v(256);
        int arr[256]={0};
        for(int i=0;i<s.length();i++){
            int id = s[i]-' ';
            arr[id]++;
            v[id].first = id;
            v[id].second = arr[id];
        }
        sort(v.begin(),v.end(),sortbysec);
        string ans = "";
        for(int i=0;i<257;i++){
            // cout<<v[i].first<<" "<<v[i].second<<"=";
            if(v[i].second==0)
                break;
             // cout<<i <<" ";
           
            ans = ans+string(v[i].second,char(v[i].first +' '));
          
            
            
        }
        cout<<ans;
        return ans;
    }
    static bool sortbysec(const pair<int,int> &a, 
              const pair<int,int> &b) 
    { 
        return (a.second > b.second); 
    }
};
