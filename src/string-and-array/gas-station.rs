impl Solution {
    pub fn can_complete_circuit(gas: Vec<i32>, cost: Vec<i32>) -> i32 {
        let n = gas.len() as i32;
        let mut i = 0;
        while i < n {
            let mut sum_of_gas = 0;
            let mut sum_of_cost = 0;
            let mut cnt = 0;
            while cnt < n {
                let j = ((i + cnt) % n) as usize;
                sum_of_gas += gas[j];
                sum_of_cost += cost[j];
                if sum_of_cost > sum_of_gas {
                    break;
                }
                cnt += 1;
            }

            if cnt == n {
                return i;
            }

            // 如果从i无法到达终点，那么i到i+cnt之间的点也无法到达终点，因为
            // 从i点开始时到达其他地方它会拥有余油仍然无法达到终点，其他点在没有余油的情况下
            // 就更不可能到达终点了
            i += cnt + 1;
        }
        return -1;
    }
}
