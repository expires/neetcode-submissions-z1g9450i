class TimeMap {
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        m[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        int l = 0; int r = m[key].size() - 1;
        
        string rr = "";

        while (l <= r)
        {
            int mid = l + ((r - l)/2);
            if (m[key][mid].first == timestamp)
            {
                rr = m[key][mid].second;
                break;
            }
            else if (m[key][mid].first > timestamp)
            {
                r = mid - 1;
            }
            else
            {
                rr = m[key][mid].second;
                l = mid + 1;
            }
            
        }

        return rr;
    }
private:
    unordered_map<string, vector<pair<int,string>>> m;
};
