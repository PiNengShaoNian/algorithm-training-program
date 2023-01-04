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
        //  当点数小于2，直接返回，应为他们始终能放到一条线上
        if (n <= 2)
        {
            return n;
        }

        int ret = 0;

        // 枚举一个端点
        for (int i = 0; i < n; ++i)
        {
            // 优化条件
            // (1). 当当前答案已经大于等于剩下所有点数量没有必要在往下枚举了
            //      不会有更大的答案了
            // (2). 当答案已经大于所有点数的一半，没有必要继续枚举了，不会有
            //      有更大的答案了，因为不会存在两条线上的点都大于 n / 2
            if (ret >= n - i || ret > n / 2)
            {
                break;
            }

            // 计算经过i点的这些线上点的数量
            // 一个斜率和一个点确定一条线
            // key: 斜率   value: 该斜率下并且经过i点的线段上其他点在这条线上的数量
            unordered_map<int, int> count;
            // 枚举另一个端点
            for (int j = i + 1; j < n; ++j)
            {
                // 斜率几个需要关注的点
                // (1). 2 / 4和1 / 2有着相同的斜率，因此我们需要同时将分子和分母
                //      同时除以他们的最大公约数
                // (2). 当x或者y为零时此时不管另一个值为多少时他们的斜率时完全时相同的
                //      因此当x为0时将y置为零，当y为0时将x置为零(题目保证不会有相同的点
                //      所以x和y不会同时为零)
                // (3). -1 / 2 和 1 / -2 是完全等价的，在这里为了方便统一表示，当y小于0
                //      时我们同时将x和y同时取相反数
                int x = points[j][0] - points[i][0];
                int y = points[j][1] - points[i][1];

                if (x == 0)
                {
                    // 处理 case (1)
                    y = 1;
                }
                else if (y == 0)
                {
                    // 处理 case (1)
                    x = 1;
                }
                else
                {
                    if (y < 0)
                    {
                        // 处理 case (3)
                        x = -x;
                        y = -y;
                    }

                    // 处理 case (2)
                    int g = gcd(abs(x), abs(y));
                    x /= g;
                    y /= g;
                }

                // 完全可以将x和y表示的斜率压缩到int中
                // 考虑到在我们的表示中y不会为负数(因为case 3),并且-10^4 <= xi, yi <= 10^4
                // 0 <= y <= 2 * 10 ^ 4,所以可以将y放在低位，将x放在高位(x * 20001)
                count[y + x * 20001]++;
            }

            int maxn = 0;
            for (auto &[_, num] : count)
            {
                // num没有统计i本身，在这里需要加上
                maxn = max(maxn, num + 1);
            }

            ret = max(maxn, ret);
        }

        return ret;
    }
};