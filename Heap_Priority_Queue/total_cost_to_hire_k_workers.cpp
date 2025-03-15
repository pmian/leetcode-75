// https://leetcode.com/problems/total-cost-to-hire-k-workers/?envType=study-plan-v2&envId=leetcode-75

class Solution
{
public:
    long long totalCost(vector<int> &costs, int k, int candidates)
    {
        int n = costs.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq; // min heap
        int left = 0, right = n - 1;
        long long total = 0;

        // Initial filling of candidates from both ends
        for (; left < candidates && left <= right; left++)
        {
            pq.push({costs[left], left});
        }
        for (; n - 1 - right < candidates && right >= left; right--)
        {
            pq.push({costs[right], right});
        }

        // Process k workers
        for (int i = 0; i < k; i++)
        {
            auto [cost, idx] = pq.top();
            pq.pop();
            total += cost;

            // Add next candidate from appropriate end
            if (left <= right)
            {
                if (idx < left)
                { // Took from left
                    pq.push({costs[left], left});
                    left++;
                }
                else
                { // Took from right
                    pq.push({costs[right], right});
                    right--;
                }
            }
        }

        return total;
    }
};