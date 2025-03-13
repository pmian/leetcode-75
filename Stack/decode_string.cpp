// https://leetcode.com/problems/decode-string/?envType=study-plan-v2&envId=leetcode-75

class Solution
{
public:
    string decodeString(string s)
    {
        stack<string> strStack;
        stack<int> numStack;
        int currNum = 0;
        string currStr = "";

        for (int i : s)
        {
            if (isdigit(i))
            {
                currNum = currNum * 10 + (i - '0');
            }
            else if (i == '[')
            {
                strStack.push(currStr);
                numStack.push(currNum);
                currStr = "";
                currNum = 0;
            }
            else if (i == ']')
            {
                string temp = "";
                int num = numStack.top();
                numStack.pop();
                string lastStr = strStack.top();
                strStack.pop();

                for (int i = 0; i < num; i++)
                {
                    temp += currStr;
                }

                currStr = lastStr + temp;
            }
            else
            {
                currStr += i;
            }
        }

        return currStr;
    }
};