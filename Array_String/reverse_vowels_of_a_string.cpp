// https://leetcode.com/problems/reverse-vowels-of-a-string/description/?envType=study-plan-v2&envId=leetcode-75

class Solution
{
public:
    string reverseVowels(string s)
    {
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};

        int left = 0, right = s.length() - 1; // Two pointers

        while (left < right)
        {
            // Move the left pointer to the right until a vowel is found
            while (left < right && vowels.find(s[left]) == vowels.end())
            {
                left++;
            }
            // Move the right pointer to the left until a vowel is found
            while (left < right && vowels.find(s[right]) == vowels.end())
            {
                right--;
            }
            // Swap the vowels
            swap(s[left], s[right]);
            // Move both pointers
            left++;
            right--;
        }

        return s;
    }
};