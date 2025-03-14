// https://leetcode.com/problems/implement-trie-prefix-tree/description/?envType=study-plan-v2&envId=leetcode-75

struct TrieNode
{
    TrieNode *children[26]; // Array for storing 26 lowercase letters
    bool end;               // Marks the end of a word

    TrieNode()
    {
        end = false;
        for (int i = 0; i < 26; i++)
            children[i] = nullptr;
    }
};

class Trie
{
public:
    TrieNode *root;

    Trie()
    {
        root = new TrieNode();
    }

    void insert(string word)
    {
        TrieNode *temp = root;
        for (char ch : word)
        {
            int idx = ch - 'a';
            if (!temp->children[idx])
                temp->children[idx] = new TrieNode();
            temp = temp->children[idx];
        }
        temp->end = true; // Mark end of the word
    }

    bool search(string word)
    {
        TrieNode *temp = root;
        for (char ch : word)
        {
            int idx = ch - 'a';
            if (!temp->children[idx])
                return false;
            temp = temp->children[idx];
        }
        return temp->end; // Return true only if it's a complete word
    }

    bool startsWith(string prefix)
    {
        TrieNode *temp = root;
        for (char ch : prefix)
        {
            int idx = ch - 'a';
            if (!temp->children[idx])
                return false;
            temp = temp->children[idx];
        }
        return true; // True as long as the prefix exists
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */