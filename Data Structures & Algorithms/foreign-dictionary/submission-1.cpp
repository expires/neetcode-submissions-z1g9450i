class Solution {
    unordered_map<char, unordered_set<char>> adj;
    unordered_set<char> visited;
    unordered_set<char> done;
    string res;
public:
    string foreignDictionary(vector<string>& words) {
        for (int i = 0; i < words.size() - 1; i++) {
            string w1 = words[i], w2 = words[i+1];
            if (w1.size() > w2.size() && w1.substr(0, w2.size()) == w2) return "";
            
            int minLen = min(w1.size(), w2.size());
            for (int j = 0; j < minLen; j++) {
                if (w1[j] != w2[j]) {
                    adj[w1[j]].insert(w2[j]); 
                    break; 
                }
            }
        }

        unordered_set<char> chars;
        for (auto& w : words)
            for (char c : w) chars.insert(c);

        // dfs over all chars
        for (char c : chars)
            if (!dfs(c)) return "";

        reverse(res.begin(), res.end());
        return res;
    }

    bool dfs(char c) {
        if (visited.count(c)) return false; 
        if (done.count(c)) return true;

        visited.insert(c);
        for (char neighbor : adj[c]) {
            if (!dfs(neighbor)) return false;
        }
        visited.erase(c);
        done.insert(c);
        res += c; 
        return true;
    }
};
