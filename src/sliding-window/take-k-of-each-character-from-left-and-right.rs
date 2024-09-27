impl Solution {
    pub fn take_characters(s: String, k: i32) -> i32 {
        let mut cnt = vec![0; 3];
        let len = s.len();
        let mut ans = len as i32;

        for c in s.chars() {
            cnt[c as usize - 'a' as usize] += 1;
        }

        if cnt[0] >= k && cnt[1] >= k && cnt[2] >= k {
            ans = ans.min(len as i32);
        } else {
            return -1;
        }

        let mut l = 0;
        let s_chars: Vec<char> = s.chars().collect();
        for r in 0..len {
            cnt[s_chars[r] as usize - 'a' as usize] -= 1;
            while l < r && (cnt[0] < k || cnt[1] < k || cnt[2] < k) {
                cnt[s_chars[l] as usize - 'a' as usize] += 1;
                l += 1;
            }
            if cnt[0] >= k && cnt[1] >= k && cnt[2] >= k {
                ans = ans.min(len as i32 - (r - l + 1) as i32);
            }
        }
        return ans;
    }
}
