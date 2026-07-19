class StockSpanner { 
public:
    stack<pair<int, int>> st;
    StockSpanner() {
    }
    
    int next(int price) {
        int span = 1;
        while (!st.empty() && st.top().first <= price) {
            span += st.top().second;
            st.pop();
        }
        st.push({price, span});
        return span;
        // int curr = 1;
        // stack<int>temp;
        // while(!store.empty()&&store.top()<=price){
        //     temp.push(store.top());
        //     store.pop();
        //     curr++;
        // }
        // while(!temp.empty()){
        //     store.push(temp.top());
        //     temp.pop();
        // }
        // store.push(price);
        // return curr;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */