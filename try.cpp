class Solution
{
public:
    int minValidStrings(vector &words, string target)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, -1});
        int n = target.size();
        vector dist(n, INT_MAX);
        while (!pq.empty())
        {
            int times = pq.top().first;
            int ind = pq.top().second;
            if (times >= n)
                break;
            pq.pop();
            int m = words.size();
            for (int i = 0; i < m; i++)
            {
                int j = ind + 1;
                int k = 0;
                while (j < n && k < words[i].size())
                {
                    if (target[j] == words[i][k])
                    {
                        if (dist[j] > times + 1)
                        {
                            dist[j] = times + 1;
                            pq.push({times + 1, j});
                        }
                        j++;
                        k++;
                    }
                    else
                        break;
                }
                if (j == n)
                    return times + 1;
            }
        }
        return -1;
    }
};