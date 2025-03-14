// https://leetcode.com/problems/search-suggestions-system/?envType=study-plan-v2&envId=leetcode-75

class Solution
{
public:
    vector<vector<string>> suggestedProducts(vector<string> &products, string searchWord)
    {
        sort(products.begin(), products.end()); // Step 1: Sort products lexicographically
        vector<vector<string>> result;
        string prefix;
        auto it = products.begin();

        for (char ch : searchWord)
        {
            prefix += ch;
            it = lower_bound(it, products.end(), prefix); // Binary search for prefix position
            vector<string> suggestions;

            for (int i = 0; i < 3 && (it + i) != products.end(); i++)
            {
                if ((it + i)->find(prefix) == 0)
                { // Check if it's a valid prefix match
                    suggestions.push_back(*(it + i));
                }
            }
            result.push_back(suggestions);
        }
        return result;
    }
};