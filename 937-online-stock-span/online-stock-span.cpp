class StockSpanner {
public:
    stack<int> s;
    unordered_map<int , int > mp;
    StockSpanner() {
        
    }
    
    int next(int price) {
        int span = 1;
      
        while(!s.empty() && price >= s.top()){
            span+=mp[s.top()];
            s.pop();
        }
        mp[price]=span;
        s.push(price);
        return mp[price];
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */