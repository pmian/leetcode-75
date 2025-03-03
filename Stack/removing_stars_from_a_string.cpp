// https://leetcode.com/problems/removing-stars-from-a-string/?envType=study-plan-v2&envId=leetcode-75

class Solution
{
public:
    string removeStars(string s)
    {
        string ans = "";
        stack<char> st;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '*')
            {
                st.pop();
            }
            else
            {
                st.push(s[i]);
            }
        }

        while (!st.empty())
        {
            ans += st.top();
            st.pop();
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};