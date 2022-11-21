// 单调栈解法
class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> stack;
        int n = height.size();
        int ans = 0;

        for(int i = 0; i < n; ++i) {
            while(stack.size() && height[i] > height[stack.back()]) {
                int top = stack.back();
                stack.pop_back();
                if(stack.empty()) break;

                int left = stack.back();
                int width = i - left - 1;
                ans += width * (min(height[left], height[i]) - height[top]);
            }

            stack.push_back(i);
        }

        return ans;
    }
};

// 双指针解法
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int left = 0;
        int right = n - 1;
        int leftMax = 0;
        int rightMax = 0;
        int ans = 0;
        // 轮流从左边边界选取一块板来做左右边界，当一边的板成为瓶颈时，就为该边界寻找更长的板
        // 我们可以安全的缩小成为瓶颈的这一边，因为答案的大小总是取决于短板这边，他能盛的水已经确定
        while(left < right) {
            leftMax = max(leftMax, height[left]);
            rightMax = max(rightMax, height[right]);

            // 盛水的左边界已经成最短那块板了，累加答案向右为左边界寻找更长的板
            if(height[left] < height[right]) {
                // 能进入这说明leftMax < rightMax，left这个位置能盛多少水只与leftMax有关
                ans += leftMax - height[left];
                ++left;
            } else {
                // 能进入这说明leftMax >= rightMax，right这个位置能盛多少水只与rightMax有关
                ans += rightMax - height[right];
                --right;
            }
        }

        return ans;
    }
};