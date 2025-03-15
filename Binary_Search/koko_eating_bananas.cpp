// https://leetcode.com/problems/koko-eating-bananas/description/?envType=study-plan-v2&envId=leetcode-75

class Solution
{
public:
    int minEatingSpeed(vector<int> &piles, int h)
    {
        int low = 1, high = *max_element(piles.begin(), piles.end());

        while (low < high)
        {
            int mid = low + (high - low) / 2;

            int hours = 0;
            for (int bananas : piles)
            {
                hours += ceil((double)bananas / mid); // Calculate hours needed
            }

            if (hours > h)
            {
                low = mid + 1; // Need a faster eating speed
            }
            else
            {
                high = mid; // Try to minimize k
            }
        }

        return low;
    }
};