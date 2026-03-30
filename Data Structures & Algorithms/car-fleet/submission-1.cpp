class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> v;
        
        for (int i = 0; i < position.size(); i++)
        {
            v.push_back({position[i], speed[i]});
        }
        sort(v.rbegin(), v.rend());

        stack<double> ss;
        for (auto& [p,s] : v)
        {
            double t = (double) (target - p) / s;
            if (ss.empty() || ss.top() < t)
            {
                ss.push(t);
            }
        }

        return ss.size();

    }
};
