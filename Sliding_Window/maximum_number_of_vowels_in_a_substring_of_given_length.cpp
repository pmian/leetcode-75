// https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length/?envType=study-plan-v2&envId=leetcode-75

class Solution
{
public:
    int maxVowels(string s, int k)
    {
        // Set of vowels for quick lookup
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        int max_vowels = 0;
        int current_vowels = 0;

        // Initialize the count of vowels in the first window
        for (int i = 0; i < k; ++i)
        {
            if (vowels.find(s[i]) != vowels.end())
            {
                current_vowels++;
            }
        }
        max_vowels = current_vowels;

        // Slide the window through the string
        for (int i = k; i < s.size(); ++i)
        {
            // Remove the leftmost character of the previous window
            if (vowels.find(s[i - k]) != vowels.end())
            {
                current_vowels--;
            }
            // Add the new character to the window
            if (vowels.find(s[i]) != vowels.end())
            {
                current_vowels++;
            }
            // Update the maximum number of vowels
            max_vowels = max(max_vowels, current_vowels);
        }

        return max_vowels;
    }
};