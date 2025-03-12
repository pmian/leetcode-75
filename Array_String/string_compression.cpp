// https://leetcode.com/problems/string-compression/description/?envType=study-plan-v2&envId=leetcode-75

class Solution
{
public:
    int compress(vector<char> &chars)
    {
        int i = 0, cnt = 0, n = chars.size();
        char ch = chars[0];
        string str = "";
        while (i < n)
        {
            while (i < n and ch == chars[i])
                i++, cnt++;
            str += ch;
            if (cnt > 1)
                str += to_string(cnt);
            if (i < n)
                ch = chars[i], cnt = 0;
        }

        chars.clear();
        for (int i = 0; i < str.size(); i++)
        {
            chars.push_back(str[i]);
        }

        return str.size();
    }
};