// https://leetcode.com/problems/merge-strings-alternately/description/?envType=study-plan-v2&envId=leetcode-75

class Solution
{
public:
    bool checkWord(int i, int j)
    {
        return i < j;
    }
    string mergeAlternately(string word1, string word2)
    {
        string ans = "";
        int m = word1.size();
        int n = word2.size();

        int i, j;
        i = j = 0;

        while (i < m || j < n)
        {
            if (checkWord(i, m))
            {
                ans += word1[i];
                i++;
            }
            if (checkWord(j, n))
            {
                ans += word2[j];
                j++;
            }
        }
        return ans;
    }
};