// https://leetcode.com/problems/can-place-flowers/description/?envType=study-plan-v2&envId=leetcode-75

class Solution
{
public:
    bool canPlaceFlowers(vector<int> &flowerbed, int n)
    {
        int length = flowerbed.size();

        for (int i = 0; i < length; i++)
        {
            if (flowerbed[i] == 0)
            {
                bool prevEmpty = (i == 0 || flowerbed[i - 1] == 0);
                bool nextEmpty = (i == length - 1 || flowerbed[i + 1] == 0);

                if (prevEmpty & nextEmpty)
                {
                    flowerbed[i] = 1;
                    n--;
                }
                if (!n)
                    return true;
            }
        }
        return n <= 0;
    }
};