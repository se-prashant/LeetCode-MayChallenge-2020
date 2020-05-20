//https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/536/week-3-may-15th-may-21st/3334/
class StockSpanner {
public:
    stack<pair<int,int>> s;
    int counter ;
    StockSpanner() {
        counter =-1;
    }
   
    int next(int price) {
        counter++;
        cout<<price<<" ";
        
        while(!s.empty() && s.top().second<=price){
            s.pop();    
        }
        int ans = s.empty()?(counter+1):(counter-s.top().first);
        s.push({counter,price});
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
