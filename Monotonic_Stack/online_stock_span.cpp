// https://leetcode.com/problems/online-stock-span/?envType=study-plan-v2&envId=leetcode-75

class StockSpanner
{
public:
    stack<pair<int, int>> st; // Stack stores {price, span}

    StockSpanner() {}

    int next(int price)
    {
        int span = 1;

        // Pop all elements that have a price <= current price
        while (!st.empty() && st.top().first <= price)
        {
            span += st.top().second;
            st.pop();
        }

        st.push({price, span});
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */