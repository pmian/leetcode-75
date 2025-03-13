// https://leetcode.com/problems/find-the-difference-of-two-arrays/description/?envType=study-plan-v2&envId=leetcode-75

class Solution
{
public:
    vector<vector<int>> findDifference(vector<int> &nums1, vector<int> &nums2)
    {
        // Convert nums1 and nums2 to sets to remove duplicates
        unordered_set<int> set1(nums1.begin(), nums1.end());
        unordered_set<int> set2(nums2.begin(), nums2.end());

        // Find elements in nums1 but not in nums2
        vector<int> distinctInNums1;
        for (int num : set1)
        {
            if (set2.find(num) == set2.end())
            {
                distinctInNums1.push_back(num);
            }
        }

        // Find elements in nums2 but not in nums1
        vector<int> distinctInNums2;
        for (int num : set2)
        {
            if (set1.find(num) == set1.end())
            {
                distinctInNums2.push_back(num);
            }
        }

        // Return the result as a list of two lists
        return {distinctInNums1, distinctInNums2};
    }
};