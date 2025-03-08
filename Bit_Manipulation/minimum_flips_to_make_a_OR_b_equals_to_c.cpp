// https://leetcode.com/problems/minimum-flips-to-make-a-or-b-equal-to-c/?envType=study-plan-v2&envId=leetcode-75

class Solution
{
public:
    int minFlips(int a, int b, int c)
    {
        int ans = 0;

        while (c || b || a)
        {
            if (c & 1)
            {
                if (!(a & 1 || b & 1))
                    ans++; // Shortened this part
            }
            else
            {
                ans += (a & 1) + (b & 1);
            }
            c >>= 1;
            a >>= 1;
            b >>= 1;
        }

        return ans;
    }
};
