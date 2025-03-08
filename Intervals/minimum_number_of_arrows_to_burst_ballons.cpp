// https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/?envType=study-plan-v2&envId=leetcode-75

class Solution
{
public:
    int findMinArrowShots(vector<vector<int>> &points)
    {
        if (points.empty())
            return 0;

        // Step 1: Sort balloons by xend (right boundary)
        sort(points.begin(), points.end(), [](const vector<int> &a, const vector<int> &b)
             {
                 return a[1] < b[1]; // Sort by end position
             });

        int arrows = 1; // First arrow at the end of the first balloon
        int lastEnd = points[0][1];

        // Step 2: Iterate through balloons
        for (int i = 1; i < points.size(); i++)
        {
            if (points[i][0] > lastEnd)
            {
                // If the current balloon starts AFTER lastEnd, a new arrow is needed
                arrows++;
                lastEnd = points[i][1]; // Update lastEnd to the new arrow's position
            }
            // Otherwise, it's already covered by the previous arrow
        }

        return arrows;
    }
};