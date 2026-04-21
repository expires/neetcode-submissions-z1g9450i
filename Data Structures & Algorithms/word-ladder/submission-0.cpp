class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        return bfs(beginWord, endWord, wordSet);
        
    }

    int bfs(string curWord, string endWord, unordered_set<string>& wordSet)
    {

        queue<string> q;
        q.push(curWord);
        int steps = 1;

        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                string word = q.front(); q.pop();
                for (int k = 0; k < word.size(); k++)
                {
                    for (int j = 0; j < 26; j++)
                    {
                        string org = word;
                        org[k] = 'a' + j;

                        if (!wordSet.count(endWord)) return 0;
                        
                        if (org == endWord) {
                            return steps + 1;
                        };
                        if (wordSet.contains(org))
                        {
                            wordSet.erase(org);
                            q.push(org);
                        }
                    }
                }
            }
            steps++; 
        }

        return 0;
    }
};
