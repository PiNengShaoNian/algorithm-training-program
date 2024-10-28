impl Solution {
    pub fn find_redundant_directed_connection(edges: Vec<Vec<i32>>) -> Vec<i32> {
        let mut cycle: i32 = -1;
        let mut conflict: i32 = -1;
        let n = edges.len();
        let mut fa: Vec<usize> = vec![0; n + 1];
        let mut parent: Vec<usize> = vec![0; n + 1];
        fn find(fa: &mut Vec<usize>, x: usize) -> usize {
            if fa[x] == x {
                return x;
            }
            fa[x] = find(fa, fa[x]);
            return fa[x];
        };
        for i in 0..=n {
            fa[i] = i;
            parent[i] = i;
        }

        for (i, edge) in edges.iter().enumerate() {
            let from = edge[0];
            let to = edge[1];
            if parent[to as usize] != to as usize {
                conflict = i as i32;
            } else {
                parent[to as usize] = from as usize;
                let parent1 = find(&mut fa, from as usize);
                let parent2 = find(&mut fa, to as usize);
                if (parent1 == parent2) {
                    cycle = i as i32;
                }
                fa[parent1] = parent2;
            }
        }

        if conflict != -1 {
            if cycle != -1 {
                return vec![
                    parent[edges[conflict as usize][1] as usize] as i32,
                    edges[conflict as usize][1] as i32,
                ];
            }
            return vec![
                edges[conflict as usize][0] as i32,
                edges[conflict as usize][1] as i32,
            ];
        } else {
            return vec![
                edges[cycle as usize][0] as i32,
                edges[cycle as usize][1] as i32,
            ];
        }
    }
}
