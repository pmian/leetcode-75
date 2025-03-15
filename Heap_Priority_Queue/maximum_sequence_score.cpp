// https://leetcode.com/problems/maximum-subsequence-score/description/?envType=study-plan-v2&envId=leetcode-75

class Solution
{
public:
    long long maxScore(vector<int> &nums1, vector<int> &nums2, int k)
    {
        vector<pair<int, int>> v;
        int n = nums1.size();

        // Step 1: Pair nums2 and nums1, then sort by nums2 in descending order
        for (int i = 0; i < n; i++)
        {
            v.push_back({nums2[i], nums1[i]});
        }
        sort(v.rbegin(), v.rend()); // Sort by nums2 decreasing

        // Step 2: Use a min-heap to maintain the k largest nums1 values
        priority_queue<int, vector<int>, greater<int>> minHeap;
        long long currSum = 0, maxScore = 0;

        for (int i = 0; i < n; i++)
        {
            minHeap.push(v[i].second);
            currSum += v[i].second;

            // Keep only k elements in the heap
            if (minHeap.size() > k)
            {
                currSum -= minHeap.top();
                minHeap.pop();
            }

            // When we have exactly k elements, calculate score
            if (minHeap.size() == k)
            {
                maxScore = max(maxScore, currSum * v[i].first);
            }
        }

        return maxScore;
    }
};