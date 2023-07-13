int maxArea(int *height, int heightSize)
{
    int l = 0;
    int r = heightSize - 1;
    int ans = 0;
#define MIN(a, b) (a < b ? a : b)
#define MAX(a, b) (a > b ? a : b)

    while (l < r)
    {
        int min = MIN(height[l], height[r]);

        ans = MAX(ans, min * (r - l));

        if (height[l] < height[r])
        {
            ++l;
        }
        else
        {
            --r;
        }
    }

    return ans;
}