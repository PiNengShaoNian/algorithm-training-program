int lower_bound(int *arr, int len, int target)
{
    int l = 0;
    int r = len - 1;

    int ans = len;
    while (l <= r)
    {
        int mid = (r - l) / 2 + l;

        if (arr[mid] == target)
        {
            ans = mid;
            r = mid - 1;
        }
        else if (arr[mid] > target)
        {
            ans = mid;
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }

    return ans;
}

void insertion_sort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void print_arr(int arr[], int len)
{
    for (int i = 0; i < len; ++i)
        printf("%d, ", arr[i]);

    printf("\n");
}

int maxSumSubmatrix(int **matrix, int matrixSize, int *matrixColSize, int max)
{
    int n = matrixSize;
    int m = *matrixColSize;
    int ans = 0x80000000;
    int sum[m];
    int sorted_arr[m + 1];

    for (int i = 0; i < n; ++i)
    {
        memset(sum, 0, sizeof(int) * m);
        for (int j = i; j < n; ++j)
        {
            for (int k = 0; k < m; ++k)
            {
                sum[k] += matrix[j][k];
            }

            memset(sorted_arr, 0, sizeof(int) * (m + 1));

            sorted_arr[0] = 0;
            int len = 1;
            int presum_right = 0;

            for (int k = 0; k < m; ++k)
            {
                presum_right += sum[k];
                int presum_left_idx = lower_bound(sorted_arr, len, presum_right - max);

                if (presum_left_idx != len)
                {
                    int presum_left = sorted_arr[presum_left_idx];
                    if (presum_right - presum_left > ans)
                        ans = presum_right - presum_left;
                }

                sorted_arr[len] = presum_right;
                ++len;
                insertion_sort(sorted_arr, len);
            }
        }
    }

    return ans;
}