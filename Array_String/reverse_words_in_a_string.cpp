// https://leetcode.com/problems/reverse-words-in-a-string/?envType=study-plan-v2&envId=leetcode-75

class Solution
{
public:
    string reverseWords(string s)
    {
        int n = s.size();
        int left = 0, right = 0;

        while (right < n)
        {
            while (right < n && s[right] == ' ')
                right++;
            while (right < n && s[right] != ' ')
                s[left++] = s[right++];
            while (right < n && s[right] == ' ')
                right++;
            if (right < n)
                s[left++] = ' ';
        }
        s.resize(left);
        reverse(s.begin(), s.end());
        int start = 0;

        for (int end = 0; end < left; end++)
        {
            if (s[end] == ' ')
            {
                reverse(s.begin() + start, s.begin() + end);
                start = end + 1;
            }
        }
        reverse(s.begin() + start, s.begin() + left);
        return s;
    }
};