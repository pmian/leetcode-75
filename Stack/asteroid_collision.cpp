// https://leetcode.com/problems/asteroid-collision/?envType=study-plan-v2&envId=leetcode-75

class Solution
{
public:
    vector<int> asteroidCollision(vector<int> &asteroids)
    {
        vector<int> stack;

        for (int ast : asteroids)
        {
            bool destroyed = false;

            while (!stack.empty() && ast < 0 && stack.back() > 0)
            { // Collision occurs
                if (abs(ast) > abs(stack.back()))
                {
                    stack.pop_back(); // Destroy the top asteroid
                    continue;         // Continue checking for further collisions
                }
                else if (abs(ast) == abs(stack.back()))
                {
                    stack.pop_back(); // Both explode
                }
                destroyed = true; // Current asteroid is destroyed
                break;
            }

            if (!destroyed)
            {
                stack.push_back(ast); // Add surviving asteroid
            }
        }

        return stack;
    }
};