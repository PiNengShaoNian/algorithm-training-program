class Solution
{
public:
    int maxSizeSlices(vector<int> &slices)
    {
        vector<int> v1(slices.begin() + 1, slices.end());
        vector<int> v2(slices.begin(), slices.end() - 1);

        return max(calc(v1), calc(v2));
    }

    int calc(vector<int> &nums)
    {
        int n = nums.size();
        int chosen = n / 3 + 1;

        vector<vector<int>> dp(n + 1, vector<int>(chosen + 1, 0));

        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= chosen; ++j)
            {
                dp[i][j] = max(dp[i - 1][j], (i - 2 < 0 ? 0 : dp[i - 2][j - 1]) + nums[i - 1]);
            }
        }

        return dp[n][chosen];
    }
};

struct Node
{
    int l;
    int r;
    int v;
};

vector<Node> nodes;

struct Id
{
    int id;

    bool operator<(const Id &that) const
    {
        return nodes[id].v < nodes[that.id].v;
    }
};

void del(int id)
{
    nodes[nodes[id].l].r = nodes[id].r;
    nodes[nodes[id].r].l = nodes[id].l;
}

class Solution1
{
public:
    int maxSizeSlices(vector<int> &slices)
    {
        int n = slices.size();
        int chosen = n / 3;
        vector<bool> can_take(n, true);
        int k = 0;
        priority_queue<Id> pq;
        int ans = 0;

        nodes.clear();

        for (int i = 0; i < n; ++i)
        {
            nodes.emplace_back(Node{(i - 1 + n) % n, (i + 1) % n, slices[i]});
        }

        for (int i = 0; i < n; ++i)
        {
            pq.push(Id{i});
        }

        while (k < chosen)
        {
            int id = pq.top().id;
            pq.pop();

            if (can_take[id])
            {
                ans += nodes[id].v;
                int l = nodes[id].l;
                int r = nodes[id].r;
                nodes[id].v = nodes[l].v + nodes[r].v - nodes[id].v;
                can_take[l] = can_take[r] = false;
                del(l);
                del(r);
                pq.push(Id{id});
                ++k;
            }
        }

        return ans;
    }
};