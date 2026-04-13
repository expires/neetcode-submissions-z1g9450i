class Solution {
    struct TrieNode
    {
        TrieNode* children[26];
        bool isEnd;
    };
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* trie = new TrieNode({}, false);
        for (string word : words) {
            TrieNode* cur = trie;
            for (char c : word) {
                if (!cur->children[c - 'a'])
                    cur->children[c - 'a'] = new TrieNode();
                cur = cur->children[c - 'a'];
            }
            cur->isEnd = true;
        }

        vector<string> res;
        string cur;

        for (int r = 0; r < board.size(); r++)
        {
            for (int c = 0; c < board[0].size(); c++)
            {
                backtrack(board, trie, cur, c, r, res);
            }
        }
        

        return res;
    }

    void backtrack(vector<vector<char>>& board, TrieNode* word, string& cur, int c, int r, vector<string>& res)
    {
        if (r < 0 || r >= board.size() || c < 0 || c >= board[0].size()) return;
        if (board[r][c] == '#') return;

        char temp = board[r][c];

        TrieNode* next = word->children[temp - 'a'];
        if (!next) return;

        cur += temp;
        if (next->isEnd) 
        {
            res.push_back(cur);  // found a word
            next->isEnd = false;
        }
        board[r][c] = '#';
        backtrack(board, next, cur, c + 1, r, res);
        backtrack(board, next, cur, c - 1, r, res);
        backtrack(board, next, cur, c, r + 1, res);
        backtrack(board, next, cur, c, r - 1, res);
        board[r][c] = temp;
        cur.pop_back();
    }
};
