int compareFunc(int *a, int *b)
{
    if (a[0] == b[0])
    {
        return b[1] - a[1];
    }

    return a[0] - b[0];
}

int partition(int **arr, int l, int r)
{
    int pivot = l + rand() % (r - l + 1);
    int *pivotVal = arr[pivot];

    while (l <= r)
    {
        while (compareFunc(arr[l], pivotVal) < 0)
            l++;
        while (compareFunc(arr[r], pivotVal) > 0)
            r--;
        if (l == r)
            break;

        if (l < r)
        {
            int *tmp = arr[l];
            arr[l] = arr[r];
            arr[r] = tmp;
            ++l;
            --r;
        }
    }

    return r;
}

void quickSort(int **arr, int l, int r)
{
    if (l >= r)
        return;

    int p = partition(arr, l, r);

    quickSort(arr, l, p);
    quickSort(arr, p + 1, r);
}

int maxEnvelopes(int **envelopes, int envelopesSize, int *envelopesColSize)
{
    quickSort(envelopes, 0, envelopesSize - 1);

    int dp[envelopesSize];
    int n = 0;

    for (int i = 0; i < envelopesSize; ++i)
    {
        if (i == 0)
        {
            dp[0] = envelopes[0][1];
            ++n;
        }
        else if (envelopes[i][1] > dp[n - 1])
        {
            dp[n] = envelopes[i][1];
            ++n;
        }
        else
        {
            int l = 0;
            int r = n - 1;
            int num = envelopes[i][1];
            int pos = n;

            while (l <= r)
            {
                int mid = (r - l) / 2 + l;
                if (num > dp[mid])
                {
                    pos = l = mid + 1;
                }
                else if (num < dp[mid])
                {
                    pos = mid;
                    r = mid - 1;
                }
                else
                {
                    pos = mid;
                    r = mid - 1;
                }
            }

            dp[pos] = num;
        }
    }

    return n;
}