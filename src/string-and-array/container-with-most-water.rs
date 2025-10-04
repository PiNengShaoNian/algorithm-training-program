impl Solution {
    pub fn max_area(height: Vec<i32>) -> i32 {
        let mut l = 0usize;
        let mut r = height.len() - 1;
        let mut ans: i32 = 0;
        while (l < r) {
            ans = i32::max(ans, (r - l) as i32 * i32::min(height[l], height[r]));
            if height[l] < height[r] {
                l = l + 1;
            } else {
                r = r - 1;
            }
        }

        return ans;
    }
}