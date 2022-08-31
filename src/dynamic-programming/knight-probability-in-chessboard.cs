public class Solution
{
    int[,] dirs = new int[8, 2] { { -2, -1 }, { -2, 1 }, { 2, -1 }, { 2, 1 }, { -1, -2 }, { -1, 2 }, { 1, -2 }, { 1, 2 } };
    public double KnightProbability(int n, int k, int row, int column)
    {
        //dp[k][row][column]表示从棋盘上任意一点出发后经过k次 能到达row column的概率之和 所以最后直接返回dp[k][row][column]
        var dp = new double[k + 1, n, n];

        for (var step = 0; step <= k; ++step)
        {
            for (var i = 0; i < n; ++i)
            {
                for (var j = 0; j < n; ++j)
                {
                    if (step == 0)
                    {
                        dp[0, i, j] = 1.0;
                    }
                    else
                    {
                        for (var x = 0; x < 8; ++x)
                        {
                            var newR = i + dirs[x, 0];
                            var newC = j + dirs[x, 1];

                            if (newR >= 0 && newR < n && newC >= 0 && newC < n)
                            {
                                dp[step, i, j] += dp[step - 1, newR, newC] / 8;
                            }
                        }
                    }
                }
            }
        }

        return dp[k, row, column];
    }
}