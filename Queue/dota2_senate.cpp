// https://leetcode.com/problems/dota2-senate/description/?envType=study-plan-v2&envId=leetcode-75

class Solution
{
public:
    string predictPartyVictory(string senate)
    {
        int n = senate.size();
        queue<int> radiant, dire;
        for (int i = 0; i < n; i++)
        {
            if (senate[i] == 'R')
                radiant.push(i);
            else
                dire.push(i);
        }

        while (!radiant.empty() and !dire.empty())
        {
            int r = radiant.front();
            int d = dire.front();
            radiant.pop();
            dire.pop();

            if (r < d)
                radiant.push(r + n);
            else
                dire.push(d + n);
        }

        return radiant.empty() ? "Dire" : "Radiant";
    }
};