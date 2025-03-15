// https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/?envType=study-plan-v2&envId=leetcode-75

class Solution
{
public:
    vector<string> letterCombinations(string digits)
    {
        if (digits.empty())
            return {};

        vector<string> result;
        string current;
        vector<string> mapping = {
            "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

        backtrack(result, mapping, digits, current, 0);
        return result;
    }

private:
    void backtrack(vector<string> &result, vector<string> &mapping,
                   const string &digits, string &current, int index)
    {
        if (index == digits.size())
        {
            result.push_back(current);
            return;
        }

        string letters = mapping[digits[index] - '0'];
        for (char letter : letters)
        {
            current.push_back(letter);
            backtrack(result, mapping, digits, current, index + 1);
            current.pop_back();
        }
    }
};