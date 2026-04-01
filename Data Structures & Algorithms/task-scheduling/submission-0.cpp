class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<int, vector<int>> heap;
        vector<int> v(26, 0);

        for (char c : tasks)
        {
            v[(c - 'A')]++;
        }

        for (int cn : v)
        {
            if (cn > 0)
            {
                heap.push(cn);
            }
        }

        int t = 0;
        queue<pair<int,int>> q;

        while (!heap.empty() || !q.empty())
        {
            t++;

            if (heap.empty())
            {
                t = q.front().second;
            }
            else
            {
                int cn = heap.top() - 1;
                heap.pop();
                if (cn > 0)
                {
                    q.push({cn, t+n});
                }
            }

            if (!q.empty() && q.front().second == t)
            {
                heap.push(q.front().first);
                q.pop();
            }
        }


        return t;


    }
};
