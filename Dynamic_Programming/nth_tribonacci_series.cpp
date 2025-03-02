// https://leetcode.com/problems/n-th-tribonacci-number/?envType=study-plan-v2&envId=leetcode-75

class Solution
{
public:
    int tribonacci(int n)
    {
        // Base cases
        if (n == 0)
            return 0;
        if (n == 1 || n == 2)
            return 1;

        // Initialize the first three Tribonacci numbers
        int t0 = 0, t1 = 1, t2 = 1;

        // Compute Tribonacci numbers up to n
        for (int i = 3; i <= n; ++i)
        {
            int tn = t0 + t1 + t2; // Compute the next Tribonacci number
            t0 = t1;               // Update t0
            t1 = t2;               // Update t1
            t2 = tn;               // Update t2
        }

        return t2; // Return the n-th Tribonacci number
    }
};