// https://leetcode.com/problems/determine-if-two-strings-are-close/description/?envType=study-plan-v2&envId=leetcode-75

class Solution
{
public:
    bool closeStrings(string word1, string word2)
    {
        // Check if the lengths are different
        if (word1.size() != word2.size())
        {
            return false;
        }

        // Count frequency of each character in word1 and word2
        unordered_map<char, int> freq1, freq2;
        for (char c : word1)
        {
            freq1[c]++;
        }
        for (char c : word2)
        {
            freq2[c]++;
        }

        // Check if the character sets are the same
        for (auto &pair : freq1)
        {
            if (freq2.find(pair.first) == freq2.end())
            {
                return false;
            }
        }
        for (auto &pair : freq2)
        {
            if (freq1.find(pair.first) == freq1.end())
            {
                return false;
            }
        }

        // Extract frequency counts and sort them
        vector<int> counts1, counts2;
        for (auto &pair : freq1)
        {
            counts1.push_back(pair.second);
        }
        for (auto &pair : freq2)
        {
            counts2.push_back(pair.second);
        }
        sort(counts1.begin(), counts1.end());
        sort(counts2.begin(), counts2.end());

        // Compare sorted frequency counts
        return counts1 == counts2;
    }
};