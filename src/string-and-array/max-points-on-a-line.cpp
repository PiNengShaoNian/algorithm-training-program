class Solution
{
public:
    int gcd(int a, int b)
    {
        return b ? gcd(b, a % b) : a;
    }

    int maxPoints(vector<vector<int>> &points)
    {
        int n = points.size();
        if (n <= 2)
        {
            return n;
        }

        int ret = 0;

        for (int i = 0; i < n; ++i)
        {
            // if(ret > (n / 2) || ret >= (n - i)) break;
            if (ret >= n - i || ret > n / 2)
            {
                break;
            }
            unordered_map<int, int> count;
            for (int j = i + 1; j < n; ++j)
            {
                int x = points[j][0] - points[i][0];
                int y = points[j][1] - points[i][1];

                if (x == 0)
                {
                    y = 1;
                }
                else if (y == 0)
                {
                    x = 1;
                }
                else
                {
                    if (y < 0)
                    {
                        x = -x;
                        y = -y;
                    }
                    int g = gcd(abs(x), abs(y));
                    x /= g;
                    y /= g;
                }
                count[y + x * 20001]++;
            }

            int maxn = 0;
            for (auto &[_, num] : count)
            {
                maxn = max(maxn, num + 1);
            }

            ret = max(maxn, ret);
        }

        return ret;
    }
};