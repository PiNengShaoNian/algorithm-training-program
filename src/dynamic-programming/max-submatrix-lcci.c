/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *getMaxMatrix(int **matrix, int matrixSize, int *matrixColSize, int *returnSize)
{
    int row1, row2, col1, col2;
    int n = matrixSize;
    int m = *matrixColSize;
    int sum[m];
    int ans = 0x80000000;

    for (int i = 0; i < n; ++i)
    {
        memset(sum, 0, sizeof(int) * m);
        for (int j = i; j < n; ++j)
        {
            for (int k = 0; k < m; ++k)
            {
                sum[k] += matrix[j][k];
            }

            int presum = 0;
            int presum_min = 0;
            int presum_min_idx = 0;

            for (int k = 0; k < m; ++k)
            {
                presum += sum[k];

                if (presum - presum_min > ans)
                {
                    ans = presum - presum_min;
                    row1 = i;
                    row2 = j;
                    col1 = presum_min_idx;
                    col2 = k;
                }

                if (presum < presum_min)
                {
                    presum_min = presum;
                    presum_min_idx = k + 1;
                }
            }
        }
    }

    int *v = (int *)malloc(sizeof(int) * 4);
    v[0] = row1;
    v[1] = col1;
    v[2] = row2;
    v[3] = col2;
    *returnSize = 4;
    return v;
}