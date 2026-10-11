class StockSpanner {
    struct SpanInfo {
        int price;
        int span;
        SpanInfo(const int price, const int span) : price(price), span(span) {}
    };
    stack<SpanInfo> s;
public:
    StockSpanner() {
        
    }
    
    int next(int price) {
        int span = 1;

        while (!s.empty() && s.top().price <= price) {
            span += s.top().span;
            s.pop();
        }

        s.push(SpanInfo(price, span));

        return span; // TC: O(n), SC: O(n)
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */