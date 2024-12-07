const DIRS: [[i32; 2]; 8] = [
    [-2, -1],
    [-2, 1],
    [2, -1],
    [2, 1],
    [-1, -2],
    [-1, 2],
    [1, -2],
    [1, 2],
];

impl Solution {
    pub fn knight_probability(n: i32, k: i32, row: i32, column: i32) -> f64 {
        let n = n as usize;
        let k = k as usize;
        // dp[step][i][j]表示在走了step步且当前位置为(i, j)时还在棋盘内的概率
        let mut dp = vec![vec![vec![0.0; n]; n]; k + 1];

        for step in 0..=k {
            for i in 0..n {
                for j in 0..n {
                    if step == 0 {
                        dp[step][i][j] = 1.0;
                    } else {
                        for dir in &DIRS {
                            let ni = i as i32 + dir[0];
                            let nj = j as i32 + dir[1];
                            if ni >= 0 && ni < n as i32 && nj >= 0 && nj < n as i32 {
                                dp[step][i][j] += dp[step - 1][ni as usize][nj as usize] / 8.0;
                            }
                        }
                    }
                }
            }
        }

        dp[k][row as usize][column as usize]
    }
}
