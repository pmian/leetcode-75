class RecentCounter
{
public:
    queue<int> q;
    RecentCounter()
    {
    }

    int ping(int t)
    {
        q.push(t); // Add the new request
        while (!q.empty() && q.front() < t - 3000)
        {
            q.pop(); // Remove outdated requests
        }
        return q.size(); // Number of valid requests in the last 3000 ms
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */