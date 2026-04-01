class Twitter {

    struct Tweet
    {
        int time;
        int uid;
        int tid;
    };

    struct Cmp {
        bool operator()(Tweet& a, Tweet& b) {
            return a.time < b.time;
        }
    };

    priority_queue<Tweet, vector<Tweet>, Cmp> heap;
    unordered_map<int, unordered_set<int>> followers;
    int timer = 0;
public:
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        timer++;
        heap.push({timer, userId, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<Tweet, vector<Tweet>, Cmp> copy = heap;
        vector<int> res;
        while (!copy.empty())
        {
            if (followers[userId].count(copy.top().uid) || copy.top().uid == userId)
            {
                res.push_back(copy.top().tid);
            }
            copy.pop();
            if (res.size() == 10) break;
        }

        return res;
    }
    
    void follow(int followerId, int followeeId) {
        followers[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        followers[followerId].erase(followeeId);
    }
};
