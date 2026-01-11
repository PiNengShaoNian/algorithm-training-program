impl Solution {
    pub fn largest_rectangle_area(heights: Vec<i32>) -> i32 {
        let n = heights.len();
        let mut left = vec![0i64; n];
        let mut right = vec![n as i64; n];
        let mut st = vec![];
        for i in 0..n {
            while !st.is_empty() && heights[*st.last().unwrap() as usize] >= heights[i] {
                right[*st.last().unwrap() as usize] = i as i64;
                st.pop();
            }
            left[i] = if st.is_empty() { -1i64 } else { *st.last().unwrap() as i64 };
            st.push(i);
        }

        let mut ans = i32::MIN;
        for i in 0..n {
            ans = i32::max(ans, (right[i] - left[i] - 1) as i32 * heights[i]);
        }
        return ans;
    }
}