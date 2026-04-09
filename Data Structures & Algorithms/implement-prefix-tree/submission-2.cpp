class PrefixTree {
    struct TrieNode
    {
        TrieNode* children[26] = {};
        bool isEnd = false;
    };

    TrieNode* root;
public:
    PrefixTree() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* cur = root;
        for (char c : word) {
            if (cur->children[c - 'a'] == nullptr)
                cur->children[c - 'a'] = new TrieNode();
            cur = cur->children[c - 'a'];
        }
        cur->isEnd = true;
    }
    
    bool search(string word) {
        TrieNode* cur = root;
        for (char c : word) 
        {
            if (cur->children[c - 'a'] == nullptr) return false;
            cur = cur->children[c - 'a'];
        }
        return cur->isEnd;
    }
    
    bool startsWith(string prefix) {
        TrieNode* cur = root;
        for (char c: prefix)
        {
            if (cur->children[c - 'a'] == nullptr) return false;
            cur = cur->children[c - 'a'];
        }

        return true;
    }
};
