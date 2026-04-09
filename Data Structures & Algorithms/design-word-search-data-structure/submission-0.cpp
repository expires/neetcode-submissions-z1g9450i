struct Trie
{
    Trie* children[26];
    bool end = false;
};

class WordDictionary {
    Trie* root;

    bool dfs(string word, int j, Trie* r)
    {
        Trie* cur = r;
        for (int i = j; i < word.size(); i++)
        {
            char c = word[i];
            if (c == '.')
            {
                for (Trie* child : cur->children)
                {
                    if (child != nullptr && dfs(word, i + 1, child))
                    {
                        return true;
                    }
                }
                return false;
            }
            else
            {
                if (cur->children[c - 'a'] == nullptr) return false;
                cur = cur->children[c - 'a'];
            }
        }
        return cur->end;
    }
public:
    WordDictionary() {
        root = new Trie();
    }
    
    void addWord(string word) {
        Trie* cur = root;
        for (char c : word) {
            if (cur->children[c - 'a'] == nullptr)
                cur->children[c - 'a'] = new Trie();
            cur = cur->children[c - 'a'];
        }
        cur->end = true;
    }
    
    bool search(string word) {
        return dfs(word, 0, root);
    }
};
