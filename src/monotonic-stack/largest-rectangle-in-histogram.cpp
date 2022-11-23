// 解法1在前部加入哨兵位，让累计的宽度不会丢失
// 考虑输入 [2, 1, 2]
// 当遍历到最后的i时，此时的栈为[0,2,3]
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.insert(heights.begin(), 0);
        heights.push_back(0);
        int n = heights.size();
        vector<int> stack;
        int ans = 0;
        for(int i = 0; i < n; ++i) {
            while(stack.size() && heights[stack.back()] > heights[i]) {
                int top = stack.back();
                stack.pop_back();
                int left = stack.back();
                int right = i - 1;

                ans = max(ans, heights[top] * (right - left));
            }

            stack.push_back(i);
        }

        return ans;
    }
};

// 解法2, 显示维护累计的宽度
// 考虑输入 [2, 1, 2]
// 当遍历到最后的i时，此时的栈为[{height: 1, width: 2}, {height: 2, width: 1}]
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        struct Rect {
            int width;
            int height;
        };
        heights.push_back(0);
        int n = heights.size();
        vector<Rect> stack;
        int ans = 0;
        for(int i = 0; i < n; ++i) {
            int accumulatedWidth = 0;
            while(stack.size() && stack.back().height > heights[i]) {
                Rect r = stack.back();
                stack.pop_back();
                accumulatedWidth += r.width;

                ans = max(ans, r.height * (accumulatedWidth));
            }

            stack.emplace_back(Rect{accumulatedWidth + 1, heights[i]});
        }

        return ans;
    }
};