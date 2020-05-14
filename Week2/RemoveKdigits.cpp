//https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/535/week-2-may-8th-may-14th/3328/
class Solution {
public:
    string removeKdigits(string num, int k) {
      stack<char> st;
      string res = "";
      int n = num.length();
      for(int i = 0; i < n; i++){
         while(k && !st.empty() && st.top() > num[i]){
            st.pop();
            k--;
         }
         st.push(num[i]);
      }
      while(k--)st.pop();
      while(!st.empty()){
         res += st.top();
         st.pop();
      }
      reverse(res.begin(), res.end());
      string ans = "";
      int i = 0;
      while(i <res.size() && res[i] == '0')i++;
      for(; i < res.size(); i++)ans += res[i];
      res = ans;
      return res.size() == 0? "0" : res;
   }
};
