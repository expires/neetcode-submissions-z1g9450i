class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        
        int l = 1; int r = *max_element(piles.begin(), piles.end());
        int rate = r;

        while (l<=r)
        {
            int mid = (l + r) / 2;
            long long tt = 0;
            for (int p: piles)
            {
                tt +=  ceil(static_cast<double>(p) / mid);
            }
            
            if (tt <= h)
            {
                rate = mid;
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        
        return rate;

    }
};
